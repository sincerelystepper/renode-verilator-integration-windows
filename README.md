# Renode-Verilator Integration for Windows (MSYS2 UCRT64)

### Cycle-Accurate Heterogeneous Co-Simulation — No Linux VM Required

<br>

![Platform](https://img.shields.io/badge/Platform-Windows_MSYS2_UCRT64-0078D4?style=for-the-badge&logo=windows&logoColor=white)
![Verilator](https://img.shields.io/badge/Verilator-5.x-2E7D32?style=for-the-badge)
![Renode](https://img.shields.io/badge/Renode-1.14+-6A0DAD?style=for-the-badge)
![License](https://img.shields.io/badge/Integration_License-MIT-00C853?style=for-the-badge)
![Status](https://img.shields.io/badge/Build-Passing_On_Windows-00C853?style=for-the-badge)

<br>

*Production-grade build system and compatibility layer that enables Antmicro's Renode-Verilator co-simulation framework to compile and run natively on Windows via MSYS2 — no WSL, no Docker, no Linux VM. Resolves seven distinct cross-platform compilation barriers including C++ name mangling mismatches, missing DPI stubs, recursive include paths, and SystemC compatibility shims.*

---

## Table of Contents

1. [Why This Repository Exists](#1-why-this-repository-exists)
2. [The Seven Barriers We Broke](#2-the-seven-barriers-we-broke)
3. [Architecture Overview](#3-architecture-overview)
4. [Quick Start](#4-quick-start)
5. [Manual Build Walkthrough](#5-manual-build-walkthrough)
6. [Repository Structure](#6-repository-structure)
7. [Integrating Your Own HDL Design](#7-integrating-your-own-hdl-design)
8. [Troubleshooting & Common Errors](#8-troubleshooting--common-errors)
9. [Acknowledgements](#9-acknowledgements)

---

## 1. Why This Repository Exists

Antmicro's [Renode-Verilator Integration Library](https://github.com/antmicro/renode-verilator-integration) is the gold standard for heterogeneous co-simulation — it allows Renode to control a Verilator-compiled HDL peripheral as if it were a physical chip on a bus, with full protocol-level fidelity. However, the library and its build system are authored for Linux, with hard dependencies on:

- GNU Make for Verilator object compilation
- POSIX socket headers and linking conventions
- GCC toolchain assumptions about `extern "C"` linkage ordering
- An internal Antmicro Infrastructure header (`renode_imports.h`) that is not publicly redistributed
- Renode's C++ API surface, which underwent breaking changes at v1.14+

This repository is the result of systematically resolving every one of these barriers to produce a **single-command build** that compiles and links on Windows MSYS2 UCRT64. If you are an embedded systems engineer developing FPGA-based peripherals on a Windows workstation and need to verify your HDL against Renode's full-system emulation before silicon, this is your starting point.

---

## 2. The Seven Barriers We Broke

Each barrier below was encountered, diagnosed, and resolved during the development of this build system. They are documented here so that you understand *why* each file and fix exists — not just that it works.

### Barrier 1: C++ Name Mangling Mismatch (`extern "C"` Linkage)

**Symptom:** Linker errors for `_Z17handleMainMessagePv`, `_Z19handleSenderMessagePv`, `_Z7receivePv` — undefined references with mangled C++ symbol names.

**Root cause:** The Renode IntegrationLibrary declares DPI callback functions as `extern void handleMainMessage(void* ptr)` at lines 278–280 of `renode_bus.cpp`. Without an `extern "C"` wrapper, the C++ compiler applies name mangling, producing symbols like `_Z17handleMainMessagePv`. The DPI stub functions in `dpi_stubs.cpp` are compiled with `extern "C"` linkage, producing unmangled symbols like `handleMainMessage`. The linker cannot match mangled calls to unmangled definitions.

**Fix applied in `BUILD.sh`:**

sed -i '278s/extern void handleMainMessage/extern "C" void handleMainMessage/' src/renode_bus.cpp
sed -i '279s/extern void handleSenderMessage/extern "C" void handleSenderMessage/' src/renode_bus.cpp
sed -i '280s/extern void receive/extern "C" void receive/' src/renode_bus.cpp
Barrier 2: Undefined EXTERNAL_AS Macro
Symptom: Compilation errors — 'HandleMainMessage' has not been declared, 'voidptr' has not been declared.

Root cause: The macro EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr) is defined in renode_imports.h, a header from Antmicro's internal Infrastructure repository that is not publicly distributed. This macro generates extern "C" wrapper functions that bridge Renode's DPI interface to the Verilator model. Without the header, the macro expands to nothing, producing bare identifiers that the compiler cannot resolve.

Fix applied in BUILD.sh:

bash
sed -i 's|EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);|extern "C" void HandleMainMessage(void* ptr) { handleMainMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);|extern "C" void HandleSenderMessage(void* ptr) { handleSenderMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, Receive, receive, voidptr);|extern "C" void Receive(void* ptr) { receive(ptr); }|g' src/renode_bus.cpp
Each EXTERNAL_AS invocation is replaced with its equivalent inline extern "C" function definition, preserving the exact ABI that Renode expects.

Barrier 3: Recursive #include "src/" Include Paths
Symptom: fatal error: 'src/renode.h' file not found — the compiler searches for src/src/renode.h which does not exist.

Root cause: The IntegrationLibrary source files use include paths relative to a project root where src/ is a top-level directory. When compiled with -Isrc, the path #include "src/renode.h" resolves to src/src/renode.h — a non-existent path. This affects 27 files across the IntegrationLibrary and local source copies.

Fix applied in BUILD.sh:

bash
find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec sed -i 's|#include "src/|#include "|g' {} \;
This in-place substitution converts all #include "src/foo.h" directives to #include "foo.h", allowing the -Isrc compiler flag to resolve them correctly.

Barrier 4: Missing renode_action_enumerators.svh
Symptom: fatal error: '../hdl/includes/renode_action_enumerators.svh' file not found.

Root cause: src/renode.h includes a SystemVerilog-compatible enumerator file that defines the Renode protocol action codes (e.g., tickClock = 1, writeRequest = 2). This file exists in the IntegrationLibrary at src/IntegrationLibrary/hdl/includes/ but is not in the compiler's include path.

Fix applied in BUILD.sh:

bash
mkdir -p hdl/includes
cp src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh hdl/includes/
And the compiler flag -Ihdl/includes is added so that ../hdl/includes/renode_action_enumerators.svh resolves correctly relative to src/renode.h.

Barrier 5: Missing communication_channel.h in Source Tree
Symptom: fatal error: 'communication/communication_channel.h' file not found.

Root cause: The src/renode_bus.h header includes "communication/communication_channel.h" but the file exists only at src/IntegrationLibrary/src/communication/ — not at src/communication/ where the include path expects it.

Fix applied in BUILD.sh:

bash
mkdir -p src/communication
cp src/IntegrationLibrary/src/communication/communication_channel.h src/communication/
Barrier 6: Missing sc_time_stamp() SystemC Stub
Symptom: Linker errors — undefined reference to sc_time_stamp().

Root cause: Verilator's VCD tracing runtime (verilated_vcd_c.cpp) calls sc_time_stamp() to timestamp waveform events. This function is part of the SystemC library, which is not linked by default and is unnecessary for Renode co-simulation. A stub is required.

Fix provided in dpi_stubs.cpp:

cpp
// SystemC time stamp required by Verilator
double sc_time_stamp() {
    return 0.0;
}
Barrier 7: No GNU Make for Verilator Object Compilation
Symptom: make: command not found when attempting make -f Vagriguard_top.mk.

Root cause: MSYS2 UCRT64 does not include GNU Make by default, and even when installed, the Verilator-generated Makefile assumes POSIX paths. The alternative Vagriguard_top__ALL.a archive also requires ar, which may not be in PATH.

Fix applied in BUILD.sh: Bypass Make entirely. All Verilator-generated .cpp files are compiled directly with explicit g++ invocations and linked as individual object files. This eliminates the dependency on both make and ar.

3. Architecture Overview
text
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
│  │  (src/IntegrationLibrary/.../socket_channel.cpp)   │  │
│  │  Serialises Renode Protocol ↔ C++ objects         │  │
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
│  │  pdm_decimator · fft_engine · spi_slave           │  │
│  └────────────────────────────────────────────────────┘  │
│                                                          │
│  Stub layer: dpi_stubs.cpp                               │
│  - handleMainMessage / handleSenderMessage / receive     │
│  - sc_time_stamp                                         │
└──────────────────────────────────────────────────────────┘
The Renode framework (running as a .NET application on Windows) opens two TCP sockets to the Verilator co-simulation executable. The SocketCommunicationChannel serialises Renode's internal Protocol messages over these sockets. The RenodeAgent class deserialises them and translates each action — tickClock, writeRequest, readRequest, interrupt — into pin-level signal toggles on the Verilated FPGA model. Responses travel back over the sender socket, allowing Renode's STM32 emulation to interact with the FPGA exactly as physical silicon would.

4. Quick Start
4.1 Prerequisites
Component	Version	Installation Command
MSYS2 UCRT64	Latest	msys2.org
Verilator	5.x	pacman -S mingw-w64-ucrt-x86_64-verilator
GCC (C++17)	14.x+	pacman -S mingw-w64-ucrt-x86_64-gcc
Renode	1.14+	github.com/renode/renode/releases
4.2 Clone and Build
bash
git clone https://github.com/sincerelystepper/renode-verilator-integration-windows.git
cd renode-verilator-integration-windows

# Single-command build
chmod +x BUILD.sh
./BUILD.sh
4.3 Verify Standalone Operation
bash
./Agriguard.exe
Expected output: PDM clock toggling at ~1.6 MHz, fpga_irq low (no FAW stimulus in standalone mode).

4.4 Connect to Renode
bash
# In one terminal: start the Verilator co-simulation
./Agriguard.exe 1234 1235

# In another terminal: start Renode with your .resc script
renode -e "include @/path/to/agriguard.resc"
5. Manual Build Walkthrough
If the one-click BUILD.sh fails or you need to understand each step for integration into a CI pipeline, follow this sequence.

5.1 Compile HDL to C++ with Verilator
bash
verilator --sv --cc \
  ../path/to/your/pdm_decimator.sv \
  ../path/to/your/fft_engine.sv \
  ../path/to/your/spi_slave.sv \
  ../path/to/your/agriguard_top.sv \
  --top-module agriguard_top \
  --Mdir obj_dir \
  -Wno-fatal -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  -Wno-UNUSED -Wno-UNDRIVEN -Wno-VARHIDDEN
5.2 Apply Windows Compatibility Fixes
bash
# Fix 1: Replace EXTERNAL_AS macros with inline extern "C" functions
sed -i 's|EXTERNAL_AS(void, HandleMainMessage, handleMainMessage, voidptr);|extern "C" void HandleMainMessage(void* ptr) { handleMainMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, HandleSenderMessage, handleSenderMessage, voidptr);|extern "C" void HandleSenderMessage(void* ptr) { handleSenderMessage(ptr); }|g' src/renode_bus.cpp
sed -i 's|EXTERNAL_AS(void, Receive, receive, voidptr);|extern "C" void Receive(void* ptr) { receive(ptr); }|g' src/renode_bus.cpp

# Fix 2: Resolve C++ name mangling — wrap extern declarations in extern "C"
sed -i '278s/extern void handleMainMessage/extern "C" void handleMainMessage/' src/renode_bus.cpp
sed -i '279s/extern void handleSenderMessage/extern "C" void handleSenderMessage/' src/renode_bus.cpp
sed -i '280s/extern void receive/extern "C" void receive/' src/renode_bus.cpp

# Fix 3: Flatten recursive #include "src/" paths
find . -type f \( -name "*.cpp" -o -name "*.h" \) -exec sed -i 's|#include "src/|#include "|g' {} \;

# Fix 4: Provision missing headers and enumerator files
mkdir -p hdl/includes src/communication
cp src/IntegrationLibrary/hdl/includes/renode_action_enumerators.svh hdl/includes/
cp src/IntegrationLibrary/src/communication/communication_channel.h src/communication/
5.3 Compile and Link
bash
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
6. Repository Structure
text
renode-verilator-integration-windows/
│
├── BUILD.sh                          # One-click build (applies all 7 fixes + compiles + links)
├── README.md                         # This document
│
├── sim_main.cpp                      # User-provided: your DUT instantiation + Init() function
├── dpi_stubs.cpp                     # DPI stubs (handleMainMessage, handleSenderMessage,
│                                     #   receive, sc_time_stamp) — required on all platforms
│
├── src/                              # Renode IntegrationLibrary (local copy with fixes applied)
│   ├── renode.h                      #   Protocol struct, Action enum, LogLevel enum
│   ├── renode_bus.h                  #   RenodeAgent class declaration
│   ├── renode_bus.cpp                #   RenodeAgent implementation + EXTERNAL_AS replacements
│   ├── renode_dpi.h                  #   DPI function declarations
│   ├── renode_dpi.cpp                #   DPI socket communication layer
│   ├── renode_cfu.h                  #   CFU interface (optional, for custom function units)
│   ├── renode_cfu.cpp                #   CFU implementation (standalone test — not compiled)
│   ├── buses/                        #   Bus interface abstractions (BaseBus, BaseTargetBus, etc.)
│   ├── peripherals/                  #   Peripheral models (UART, GPIO receiver)
│   ├── communication/                #   communication_channel.h (copied from IntegrationLibrary)
│   └── IntegrationLibrary/           #   Original Antmicro IntegrationLibrary (MIT-licensed)
│       ├── src/                      #     Source files
│       ├── hdl/                      #     HDL includes (renode_action_enumerators.svh)
│       └── libs/                     #     Socket-cpp library (TCP client for Renode protocol)
│
├── hdl/includes/                     # Provisioned at build time
│   └── renode_action_enumerators.svh #   Action type enumerators (must match Renode C# Protocol)
│
├── obj_dir/                          # Verilator output (generated at build time)
│   ├── Vagriguard_top.h              #   C++ header for your DUT
│   ├── Vagriguard_top.cpp            #   C++ implementation
│   ├── Vagriguard_top__Syms.cpp      #   Symbol table
│   └── ...                           #   Additional Verilator-generated files
│
└── AgriGuard.exe                     # Final linked executable (generated at build time)
7. Integrating Your Own HDL Design
This repository is a template. Replace the AgriGuard-specific components with your own design in four steps.

Step 1: Substitute Your SystemVerilog Sources
In BUILD.sh, replace the Verilator invocation:

bash
verilator --sv --cc \
  your_top.sv \
  your_module_a.sv \
  your_module_b.sv \
  --top-module your_top_module_name \
  --Mdir obj_dir \
  -Wno-fatal -Wno-WIDTHTRUNC -Wno-WIDTHEXPAND \
  -Wno-UNUSED -Wno-UNDRIVEN -Wno-VARHIDDEN
Step 2: Update sim_main.cpp
Modify three sections:

cpp
// 1. Include your Verilated top header
#include "Vyour_top.h"

// 2. Instantiate your DUT
Vyour_top* top = new Vyour_top;

// 3. The Init() function (Renode calls this to get the agent)
RenodeAgent* Init() {
    return new RenodeAgent();
}
Step 3: Register Your Signals
Add signal registration inside Init() or main() before calling agent->connect():

cpp
// Input signals (Renode drives these)
// Example: agent->addBus(new YourBusImplementation(&top->signal, "signal_name"));

// Output signals (your DUT drives these — register interrupts)
agent->registerInterrupt(&top->your_irq_signal, 0x00);
Step 4: Verify the Build
bash
./BUILD.sh
./AgriGuard.exe
Then connect to Renode with a .resc script that defines your peripheral at the expected bus address.

8. Troubleshooting & Common Errors
undefined reference to handleMainMessage(void*)
Cause: The extern "C" fix (Barrier 1) was not applied, or dpi_stubs.cpp was not linked.
Check: Run nm AgriGuard.exe \| grep handleMainMessage. If the symbol shows as _Z17handleMainMessagePv (mangled), the extern "C" sed fix did not execute. Re-run BUILD.sh.

fatal error: 'renode_bus.h' file not found
Cause: The corrupted src/renode_bus.h (shell script content from a failed copy operation) was not replaced.
Fix: Delete src/renode_bus.h and re-run BUILD.sh. The script auto-detects and replaces corrupted headers.

undefined reference to sc_time_stamp()
Cause: dpi_stubs.cpp was not linked or was linked after the Verilator runtime.
Fix: Ensure dpi_stubs.cpp appears before verilated.cpp in the g++ invocation. Order matters.

collect2.exe: error: ld returned 1 exit status with no other messages
Cause: Most likely the Verilator-generated .cpp file list is incomplete (missing trace files if --trace was used, or missing __Syms files).
Check: ls obj_dir/*.cpp and ensure all listed files appear in the g++ command. If you used --trace, the trace files (V*__Trace*.cpp, V*__TraceDecls*.cpp) must also be compiled and linked.

#pragma comment(lib,"WS2_32.lib") warning
Harmless. The socket-cpp library uses an MSVC-specific pragma to link Winsock. Under GCC/MinGW, this pragma is ignored. The -lws2_32 linker flag handles this correctly.

9. Acknowledgements
Antmicro — for the Renode-Verilator Integration Library, released under the MIT License. The src/IntegrationLibrary/ directory contains their original work with modifications only for Windows compatibility.

Verilator — for the open-source SystemVerilog to C++ compiler that makes this co-simulation possible.

Agrionics Systems — the AgriGuard-RES project that motivated this Windows port. See the main AgriGuard-RES repository for the complete edge AI sentinel platform.

<div align="center">
Built on Windows. Verified against Renode. Deployed to the field.

Pull requests that extend platform support or add new peripheral integrations are welcome.

</div> ```
