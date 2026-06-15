# Renode-Verilator Integration for Windows (MSYS2 UCRT64)

### Cycle-Accurate Heterogeneous Co-Simulation — No Linux VM Required

<br>

![Platform](https://img.shields.io/badge/Platform-Windows_MSYS2_UCRT64-0078D4?style=for-the-badge&logo=windows&logoColor=white)
![Verilator](https://img.shields.io/badge/Verilator-5.x-2E7D32?style=for-the-badge)
![Renode](https://img.shields.io/badge/Renode-1.14+-6A0DAD?style=for-the-badge)
![License](https://img.shields.io/badge/Integration_License-MIT-00C853?style=for-the-badge)
![Status](https://img.shields.io/badge/Build-Passing_On_Windows-00C853?style=for-the-badge)

*Production-grade build system and compatibility layer that enables Antmicro's Renode-Verilator co-simulation framework to compile and run natively on Windows via MSYS2 — no WSL, no Docker, no Linux VM. Resolves seven distinct cross-platform compilation barriers including C++ name mangling mismatches, missing DPI stubs, recursive include paths, and SystemC compatibility shims.*


---

## Table of Contents


---

## Why This Repository Exists


---

## The Seven Barriers We Broke


---

## Architecture Overview


---

## Quick Start


---

## Manual Build Walkthrough


---

## Repository Structure


---

## Integrating Your Own HDL Design


---

## Troubleshooting and Common Errors


---

## Acknowledgements


---

## Why This Repository Exists
Antmicro's Renode-Verilator Integration Library is the gold standard for heterogeneous co-simulation — it allows Renode to control a Verilator-compiled HDL peripheral as if it were a physical chip on a bus, with full protocol-level fidelity. However, the library and its build system are authored for Linux, with hard dependencies on:

GNU Make for Verilator object compilation

POSIX socket headers and linking conventions

GCC toolchain assumptions about extern "C" linkage ordering

An internal Antmicro Infrastructure header (renode_imports.h) that is not publicly redistributed

Renode's C++ API surface, which underwent breaking changes at v1.14+

This repository is the result of systematically resolving every one of these barriers to produce a single-command build that compiles and links on Windows MSYS2 UCRT64. If you are an embedded systems engineer developing FPGA-based peripherals on a Windows workstation and need to verify your HDL against Renode's full-system emulation before silicon, this is your starting point.


---

## The Seven Barriers We Broke
Each barrier below was encountered, diagnosed, and resolved during the development of this build system. They are documented here so that you understand why each file and fix exists — not just that it works.

Barrier 1: C++ Name Mangling Mismatch (extern "C" Linkage)
Symptom: Linker errors for mangled C++ symbol names — _Z17handleMainMessagePv, _Z19handleSenderMessagePv, _Z7receivePv — all reported as undefined references despite the functions being visibly present in dpi_stubs.cpp.

Root cause: The Renode IntegrationLibrary declares the DPI callback functions at lines 278 through 280 of src/renode_bus.cpp as plain extern declarations without C linkage:

```text
extern void handleMainMessage(void* ptr);
extern void handleSenderMessage(void* ptr);
extern void receive(void* ptr);
In C++, an extern declaration without an explicit extern "C" wrapper is still subject to C++ name mangling. The compiler therefore emits mangled symbol references — _Z17handleMainMessagePv instead of the unmangled handleMainMessage. Meanwhile, the actual function definitions in dpi_stubs.cpp are compiled inside an extern "C" block, producing unmangled symbols. The linker cannot reconcile the two: the call site demands a mangled C++ symbol, but only an unmangled C symbol exists in the object files.

This is a subtle cross-platform linkage issue that does not manifest on Linux when using the full Antmicro Infrastructure build chain (where renode_imports.h provides macros that force C linkage at every declaration site). On Windows with a standalone build, the mismatch is fatal.

Fix applied in BUILD.sh:

```text
sed -i '278s/extern void handleMainMessage/extern "C" void handleMainMessage/' src/renode_bus.cpp
sed -i '279s/extern void handleSenderMessage/extern "C" void handleSenderMessage/' src/renode_bus.cpp
sed -i '280s/extern void receive/extern "C" void receive/' src/renode_bus.cpp
Each extern declaration is rewritten in-place to include the extern "C" linkage specifier. After this substitution, the compiler emits unmangled symbol references that correctly resolve against the unmangled definitions in dpi_stubs.cpp. The sed line numbers (278, 279, 280) are pinned to the specific version of renode_bus.cpp shipped with this repository. If you upgrade the IntegrationLibrary, verify that these declarations still appear at the same line numbers, or adjust accordingly.

Verification: Before the fix, running nm renode_bus.o | grep handle shows mangled undefined symbols with U _Z17handleMainMessagePv. After the fix, the same command shows U handleMainMessage — unmangled, and therefore resolvable against dpi_stubs.o.

Barrier 2: Undefined EXTERNAL_AS Macro
Symptom: Compilation errors at lines 282 through 284 of src/renode_bus.cpp — HandleMainMessage has not been declared, voidptr has not been declared, and expected constructor, destructor, or type conversion before semicolon token.

Root cause: The IntegrationLibrary uses a macro called EXTERNAL_AS to generate wrapper functions that bridge Renode's DPI (Direct Programming Interface) to the Verilator model. The macro is defined in renode_imports.h, which resides in Antmicro's internal Infrastructure repository — a dependency that is not publicly distributed. The three invocations in renode_bus.cpp are:

```text
EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);
EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);
EXTERNAL_AS(void, Receive, receive, voidptr);
The macro signature EXTERNAL_AS(return_type, WrapperName, TargetFunction, arg_type) is designed to expand into an extern "C" function definition that calls through to the target function. Without the macro definition available, the preprocessor leaves the tokens untouched, and the compiler encounters HandleMainMessage, handleMainMessage, and voidptr as bare identifiers with no syntactic meaning — hence the cascade of errors.

Fix applied in BUILD.sh:

```text
sed -i 's|EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);|extern "C" void HandleMainMessage(void* ptr) { handleMainMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);|extern "C" void HandleSenderMessage(void* ptr) { handleSenderMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, Receive, receive, voidptr);|extern "C" void Receive(void* ptr) { receive(ptr); }|g' src/renode_bus.cpp
Each EXTERNAL_AS invocation is replaced with its equivalent inline extern "C" function definition. The resulting code is semantically identical to what the macro would have produced. The pipe character is used as the sed delimiter instead of the conventional forward slash to avoid escaping the slashes in void*. The g flag ensures the replacement applies globally within each file.

Why this is safe: The EXTERNAL_AS macro is a purely mechanical code generation tool — it takes four arguments and produces a one-line wrapper function. By expanding it inline, we preserve the exact ABI that Renode expects while eliminating the dependency on a non-public header. No behavioural change occurs.

Barrier 3: Recursive include Paths
Symptom: Fatal compilation errors — fatal error: src/renode.h file not found — despite the file src/renode.h visibly existing on disk.

Root cause: The IntegrationLibrary source files use include directives that assume a project root where src/ is a top-level directory. For example, src/renode_bus.cpp contains:

```text
#include "src/renode.h"
When the compiler is invoked with -Isrc (meaning "search the src directory for headers"), the preprocessor concatenates the include path with the quoted string, producing the resolved path src/src/renode.h — which does not exist. The file lives at src/renode.h, not at src/src/renode.h.

This pattern affects 27 files across the IntegrationLibrary and the local source copies in the src/ directory, including bus implementations, peripheral models, and the core RenodeAgent source.

Fix applied in BUILD.sh:

```text
find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec sed -i 's|#include "src/|#include "|g' {} \;
This find command locates every C++ source and header file in the repository tree and applies an in-place sed substitution that strips the src/ prefix from all include directives. After the substitution, #include "src/renode.h" becomes #include "renode.h", which resolves correctly against the -Isrc compiler flag.

Barrier 4: Missing renode_action_enumerators.svh
Symptom: Fatal compilation error — fatal error: ../hdl/includes/renode_action_enumerators.svh file not found — originating from src/renode.h.

Root cause: The header src/renode.h includes a SystemVerilog-compatible enumerator file that defines the Renode protocol action codes:

```text
enum Action
{
#include "../hdl/includes/renode_action_enumerators.svh"
};
This include path is relative to the src/ directory, meaning the compiler looks for hdl/includes/renode_action_enumerators.svh at the project root level. The file exists inside the IntegrationLibrary at src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh, but that location is not on the compiler's include search path.

The enumerator file itself contains action type constants that must match Renode's C# ActionType enum exactly — values such as tickClock equals 1, writeRequest equals 2, readRequest equals 3, interrupt equals 6, and ok equals 9. Without this file, the Action enum is empty, and every reference to Action tickClock, Action writeRequest, and similar identifiers throughout the codebase becomes an undefined symbol.

Fix applied in BUILD.sh:

```text
mkdir -p hdl/includes
cp src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh hdl/includes/
The directory hdl/includes/ is created at the project root, and the enumerator file is copied into it. The compiler flag -Ihdl/includes (already present in the build command) ensures the path resolves correctly.

Barrier 5: Missing communication_channel.h in Source Tree
Symptom: Fatal compilation error — fatal error: communication/communication_channel.h file not found — originating from src/renode_bus.h.

Root cause: The header src/renode_bus.h declares the RenodeAgent class, which holds a pointer to an abstract CommunicationChannel:

```text
#include "communication/communication_channel.h"
The include path communication/communication_channel.h is relative to one of the compiler's -I directories. With -Isrc in the build flags, the compiler searches for src/communication/communication_channel.h. However, the original file lives at src/IntegrationLibrary/src/communication/communication_channel.h — nested one level deeper inside the IntegrationLibrary subtree. The src/communication/ directory does not exist in the repository as cloned.

Fix applied in BUILD.sh:

```text
mkdir -p src/communication
cp src/IntegrationLibrary/src/communication/communication_channel.h src/communication/
This provisions the missing directory and copies the header into the expected location. The CommunicationChannel class is a pure virtual interface that defines the contract for Renode protocol transport — any concrete implementation (such as SocketCommunicationChannel for TCP or NativeCommunicationChannel for in-process DPI) must implement sendMain, sendSender, receive, log, and isConnected. The header itself has no additional dependencies beyond renode.h, so copying it is sufficient.

Barrier 6: Missing sc_time_stamp SystemC Stub
Symptom: Linker errors — undefined reference to sc_time_stamp() — reported against verilated.cpp with no other compilation errors preceding them.

Root cause: Verilator's VCD (Value Change Dump) tracing runtime, compiled from verilated_vcd_c.cpp, internally calls sc_time_stamp() to timestamp waveform events during simulation. The function sc_time_stamp() is part of the SystemC reference implementation (libsystemc), which is a separate library that must be explicitly linked. For Renode co-simulation, VCD tracing is optional — the primary communication channel is the TCP socket protocol, not waveform files. Linking the full SystemC library solely to satisfy this one symbol is unnecessary overhead and introduces an additional dependency.

Fix provided in dpi_stubs.cpp:

```text
// SystemC time stamp required by Verilator
double sc_time_stamp() {
    return 0.0;
}
This provides a minimal stub that returns a constant zero timestamp. Verilator's tracing runtime calls this function to tag each waveform event with a time value. Since Renode co-simulation does not use VCD output as its primary data channel, the timestamp value is irrelevant — the stub satisfies the linker without pulling in the SystemC library.

Critical note on link order: The object file containing this stub (dpi_stubs.o) must appear before verilated.o and verilated_vcd_c.o in the linker command line. If the Verilator runtime object files are processed first, the linker may cache the unresolved symbol and fail to find the stub defined later. The BUILD.sh script places dpi_stubs.cpp at the front of the source file list for this reason.

Barrier 7: No GNU Make for Verilator Object Compilation
Symptom: make: command not found when attempting to compile the Verilator-generated C++ model using the standard workflow of cd obj_dir && make -f Vagriguard_top.mk.

Root cause: The MSYS2 UCRT64 environment does not include GNU Make in its default package set. Even when GNU Make is installed separately via pacman -S make, the Verilator-generated Vagriguard_top.mk Makefile assumes a POSIX file system layout with forward-slash path separators and shell utilities at standard Linux paths — assumptions that may not hold under the MSYS2 UCRT64 prefix structure.

The standard Verilator workaround is to use the static library archive Vagriguard_top__ALL.a, which bundles all generated object files into a single linkable archive. However, this approach requires the ar archiver tool, which may also be absent from a minimal MSYS2 installation, and the archive name is Verilator-version-dependent.

Fix applied in BUILD.sh: Bypass both make and ar entirely. The build script enumerates every Verilator-generated cpp file explicitly and compiles each one with a direct g++ -c invocation. The resulting dot-o files are then passed individually to the final link step. The file list is:

```text
obj_dir/Vagriguard_top.cpp
obj_dir/Vagriguard_top___024root__0.cpp
obj_dir/Vagriguard_top___024root__Slow.cpp
obj_dir/Vagriguard_top__Syms__Slow.cpp
obj_dir/Vagriguard_top___024root__0__Slow.cpp
This approach is intentionally verbose rather than using a wildcard like obj_dir/*.cpp because Verilator's output directory may contain files that should not be compiled directly (such as precompiled headers or class metadata files). Explicit enumeration guarantees that only the correct translation units are compiled.

If you used the --trace flag with Verilator, three additional trace implementation files are generated and must be included:

```text
obj_dir/Vagriguard_top__Trace__0.cpp
obj_dir/Vagriguard_top__Trace__0__Slow.cpp
obj_dir/Vagriguard_top__TraceDecls__0__Slow.cpp
The BUILD.sh script in this repository is configured for a non-trace build by default. If you add --trace to the Verilator invocation, append these three files to the source list in the g++ command.


---

## Architecture Overview
```text
┌──────────────────────────────────────────────────────────┐
│                    Renode (C# runtime)                    │
│  ┌────────────────────────────────────────────────────┐  │
│  │  Machine description (.resc)                       │  │
│  │  "iCE40HX8K co-processor at SPI address 0x00"     │  │
│  └────────────────────┬───────────────────────────────┘  │
│                       │ TCP socket (ports 1234/1235)     │
│                       ▼                                  │
│  ┌────────────────────────────────────────────────────┐  │
│  │  SocketCommunicationChannel                        │  │
│  │  Serialises Renode Protocol to C++ objects         │  │
│  └────────────────────┬───────────────────────────────┘  │
│                       │                                  │
└───────────────────────┼──────────────────────────────────┘
                        │
┌───────────────────────┼──────────────────────────────────┐
│     AgriGuard.exe     │  (Windows native executable)     │
│                       ▼                                  │
│  ┌────────────────────────────────────────────────────┐  │
│  │  RenodeAgent (src/renode_bus.cpp)                  │  │
│  │  Protocol dispatch: read, write, tick, interrupt   │  │
│  └────────────────────┬───────────────────────────────┘  │
│                       │ pin-level signal updates         │
│                       ▼                                  │
│  ┌────────────────────────────────────────────────────┐  │
│  │  Vagriguard_top (Verilator-compiled FPGA fabric)   │  │
│  │  pdm_decimator - fft_engine - spi_slave            │  │
│  └────────────────────────────────────────────────────┘  │
│                                                          │
│  Stub layer: dpi_stubs.cpp                               │
│  - handleMainMessage / handleSenderMessage / receive     │
│  - sc_time_stamp                                         │
└──────────────────────────────────────────────────────────┘
The Renode framework running as a dotNET application on Windows opens two TCP sockets to the Verilator co-simulation executable. The SocketCommunicationChannel serialises Renode's internal Protocol messages over these sockets. The RenodeAgent class deserialises them and translates each action — tickClock, writeRequest, readRequest, interrupt — into pin-level signal toggles on the Verilated FPGA model. Responses travel back over the sender socket, allowing Renode's STM32 emulation to interact with the FPGA exactly as physical silicon would.


---

## Quick Start
Prerequisites
Component	Version	Installation Command
MSYS2 UCRT64	Latest	msys2.org
Verilator	5.x	pacman -S mingw-w64-ucrt-x86_64-verilator
GCC (C++17)	14.x+	pacman -S mingw-w64-ucrt-x86_64-gcc
Renode	1.14+	github.com/renode/renode/releases
Clone and Build
```text
git clone https://github.com/sincerelystepper/renode-verilator-integration-windows.git
cd renode-verilator-integration-windows
chmod +x BUILD.sh
./BUILD.sh
Verify Standalone Operation
```text
./AgriGuard.exe
Expected output: PDM clock toggling at approximately 1.6 MHz, fpga_irq low with no FAW stimulus in standalone mode.

Connect to Renode
In one terminal start the Verilator co-simulation:

```text
./AgriGuard.exe 1234 1235
In another terminal start Renode with your resc script:

```text
renode -e "include @/path/to/agriguard.resc"

---

## Manual Build Walkthrough
If the one-click BUILD.sh fails or you need to understand each step for integration into a CI pipeline, follow this sequence.

Compile HDL to C++ with Verilator
```text
verilator --sv --cc \
  ../path/to/your/pdm_decimator.sv \
  ../path/to/your/fft_engine.sv \
  ../path/to/your/spi_slave.sv \
  ../path/to/your/agriguard_top.sv \
  --top-module agriguard_top \
  --Mdir obj_dir \
  -Wno-fatal -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  -Wno-UNUSED -Wno-UNDRIVEN -Wno-VARHIDDEN
Apply Windows Compatibility Fixes
Fix 1: Replace EXTERNAL_AS macros with inline extern "C" functions.

```text
sed -i 's|EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);|extern "C" void HandleMainMessage(void* ptr) { handleMainMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);|extern "C" void HandleSenderMessage(void* ptr) { handleSenderMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, Receive, receive, voidptr);|extern "C" void Receive(void* ptr) { receive(ptr); }|g' src/renode_bus.cpp
Fix 2: Resolve C++ name mangling by wrapping extern declarations in extern "C".

```text
sed -i '278s/extern void handleMainMessage/extern "C" void handleMainMessage/' src/renode_bus.cpp
sed -i '279s/extern void handleSenderMessage/extern "C" void handleSenderMessage/' src/renode_bus.cpp
sed -i '280s/extern void receive/extern "C" void receive/' src/renode_bus.cpp
Fix 3: Flatten recursive include paths.

```text
find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec sed -i 's|#include "src/|#include "|g' {} \;
Fix 4: Provision missing headers and enumerator files.

```text
mkdir -p hdl/includes src/communication
cp src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh hdl/includes/
cp src/IntegrationLibrary/src/communication/communication_channel.h src/communication/
Compile and Link
```text
VERILATOR_ROOT=$(verilator --getenv VERILATOR_ROOT)/include

g++ -Wall -Os -std=c++17 \
  -include cstring -include string.h \
  -I. -Iobj_dir -Isrc -Isrc/peripherals -Isrc/buses -Isrc/communication \
  -Isrc/IntegrationLibrary/src \
  -Isrc/IntegrationLibrary/src/communication \
  -Isrc/IntegrationLibrary/src/buses \
  -Isrc/IntegrationLibrary/src/peripherals \
  -Isrc/IntegrationLibrary/libs/socket-cpp/Socket \
  -Ihdl/includes -I"$VERILATOR_ROOT" \
  dpi_stubs.cpp \
  sim_main.cpp \
  src/renode_bus.cpp \
  src/renode_dpi.cpp \
  src/buses/bus.cpp \
  src/IntegrationLibrary/src/communication/socket_channel.cpp \
  src/IntegrationLibrary/libs/socket-cpp/Socket/TCPClient.cpp \
  src/IntegrationLibrary/libs/socket-cpp/Socket/Socket.cpp \
  obj_dir/Vagriguard_top.cpp \
  obj_dir/Vagriguard_top___024root__0.cpp \
  obj_dir/Vagriguard_top___024root__Slow.cpp \
  obj_dir/Vagriguard_top__Syms__Slow.cpp \
  obj_dir/Vagriguard_top___024root__0__Slow.cpp \
  "$VERILATOR_ROOT/verilated.cpp" \
  "$VERILATOR_ROOT/verilated_vcd_c.cpp" \
  "$VERILATOR_ROOT/verilated_threads.cpp" \
  -o AgriGuard.exe \
  -lws2_32 -Wno-unknown-pragmas

---

## Repository Structure
```text
renode-verilator-integration-windows/
│
├── BUILD.sh                          One-click build
├── README.md                         This document
│
├── sim_main.cpp                      User-provided DUT instantiation
├── dpi_stubs.cpp                     DPI stubs required on all platforms
│
├── src/
│   ├── renode.h                      Protocol struct and Action enum
│   ├── renode_bus.h                  RenodeAgent class declaration
│   ├── renode_bus.cpp                RenodeAgent with EXTERNAL_AS replacements
│   ├── renode_dpi.h                  DPI function declarations
│   ├── renode_dpi.cpp                DPI socket communication layer
│   ├── renode_cfu.h                  CFU interface (optional)
│   ├── renode_cfu.cpp                CFU implementation (not compiled)
│   ├── buses/                        Bus interface abstractions
│   ├── peripherals/                  Peripheral models
│   ├── communication/                communication_channel.h (provisioned)
│   └── IntegrationLibrary/           Original Antmicro library (MIT)
│       ├── src/
│       ├── hdl/
│       └── libs/
│
├── hdl/includes/                     Provisioned at build time
│   └── renode_action_enumerators.svh
│
├── obj_dir/                          Verilator output (generated)
│   ├── Vagriguard_top.h
│   ├── Vagriguard_top.cpp
│   └── ...
│
└── AgriGuard.exe                     Final linked executable

---

## Integrating Your Own HDL Design
This repository is a template. Replace the AgriGuard-specific components with your own design in four steps.

Step 1: Substitute Your SystemVerilog Sources
In BUILD.sh replace the Verilator invocation:

```text
verilator --sv --cc \
  your_top.sv \
  your_module_a.sv \
  your_module_b.sv \
  --top-module your_top_module_name \
  --Mdir obj_dir \
  -Wno-fatal -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  -Wno-UNUSED -Wno-UNDRIVEN -Wno-VARHIDDEN
Step 2: Update sim_main.cpp
Modify three sections. First, include your Verilated top header:

```text
#include "Vyour_top.h"
Second, instantiate your DUT:

```text
Vyour_top* top = new Vyour_top;
Third, the Init function that Renode calls to get the agent:

```text
RenodeAgent* Init() {
    return new RenodeAgent();
}
Step 3: Register Your Signals
Add signal registration inside Init or main before calling agent connect:

```text
agent->registerInterrupt(&top->your_irq_signal, 0x00);
Step 4: Verify the Build
```text
./BUILD.sh
./AgriGuard.exe
Then connect to Renode with a resc script that defines your peripheral at the expected bus address.


---

## Troubleshooting and Common Errors
undefined reference to handleMainMessage
Cause: The extern "C" fix from Barrier 1 was not applied, or dpi_stubs.cpp was not linked.
Check: Run nm AgriGuard.exe | grep handleMainMessage. If the symbol shows as mangled like _Z17handleMainMessagePv, the extern "C" sed fix did not execute. Re-run BUILD.sh.

fatal error: renode_bus.h file not found
Cause: The corrupted src/renode_bus.h containing shell script content from a failed copy operation was not replaced.
Fix: Delete src/renode_bus.h and re-run BUILD.sh. The script auto-detects and replaces corrupted headers.

undefined reference to sc_time_stamp
Cause: dpi_stubs.cpp was not linked or was linked after the Verilator runtime.
Fix: Ensure dpi_stubs.cpp appears before verilated.cpp in the g++ invocation. Link order matters.

collect2.exe: error: ld returned 1 exit status with no other messages
Cause: Most likely the Verilator-generated cpp file list is incomplete due to missing trace files if --trace was used, or missing Syms files.
Check: Run ls obj_dir/*.cpp and ensure all listed files appear in the g++ command. If you used --trace, the trace files must also be compiled and linked.

pragma comment lib WS2_32.lib warning
Harmless. The socket-cpp library uses an MSVC-specific pragma to link Winsock. Under GCC and MinGW this pragma is ignored. The -lws2_32 linker flag handles this correctly.


---

## Acknowledgements
Antmicro — for the Renode-Verilator Integration Library, released under the MIT License. The src/IntegrationLibrary/ directory contains their original work with modifications only for Windows compatibility.

Verilator — for the open-source SystemVerilog to C++ compiler that makes this co-simulation possible.

Agrionics Systems — the AgriGuard-RES project that motivated this Windows port.

Built on Windows. Verified against Renode. Deployed to the field.

Pull requests that extend platform support or add new peripheral integrations are welcome.
```