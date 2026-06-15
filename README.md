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

1. [Why This Repository Exists](#why-this-repository-exists)
2. [The Seven Barriers We Broke](#the-seven-barriers-we-broke)
3. [Architecture Overview](#architecture-overview)
4. [Quick Start](#quick-start)
5. [Manual Build Walkthrough](#manual-build-walkthrough)
6. [Repository Structure](#repository-structure)
7. [Integrating Your Own HDL Design](#integrating-your-own-hdl-design)
8. [Troubleshooting and Common Errors](#troubleshooting-and-common-errors)
9. [Acknowledgements](#acknowledgements)

---

## Why This Repository Exists

Antmicro's [Renode-Verilator Integration Library](https://github.com/antmicro/renode-verilator-integration) is the gold standard for heterogeneous co-simulation — it allows Renode to control a Verilator-compiled HDL peripheral as if it were a physical chip on a bus, with full protocol-level fidelity. However, the library and its build system are authored for Linux, with hard dependencies on:

- GNU Make for Verilator object compilation
- POSIX socket headers and linking conventions
- GCC toolchain assumptions about `extern "C"` linkage ordering
- An internal Antmicro Infrastructure header (`renode_imports.h`) that is not publicly redistributed
- Renode's C++ API surface, which underwent breaking changes at v1.14+

This repository is the result of systematically resolving every one of these barriers to produce a **single-command build** that compiles and links on Windows MSYS2 UCRT64. If you are an embedded systems engineer developing FPGA-based peripherals on a Windows workstation and need to verify your HDL against Renode's full-system emulation before silicon, this is your starting point.

---

## The Seven Barriers We Broke

Each barrier below was encountered, diagnosed, and resolved during the development of this build system. They are documented here so that you understand why each file and fix exists — not just that it works.

### Barrier 1: C++ Name Mangling Mismatch (extern "C" Linkage)

**Symptom:** Linker errors for mangled C++ symbol names — `_Z17handleMainMessagePv`, `_Z19handleSenderMessagePv`, `_Z7receivePv` — all reported as undefined references despite the functions being visibly present in `dpi_stubs.cpp`.

**Root cause:** The Renode IntegrationLibrary declares the DPI callback functions at lines 278 through 280 of `src/renode_bus.cpp` as plain `extern` declarations without C linkage:

Each `extern` declaration is rewritten in-place to include the `extern "C"` linkage specifier. After this substitution, the compiler emits unmangled symbol references that correctly resolve against the unmangled definitions in `dpi_stubs.cpp`. The `sed` line numbers (278, 279, 280) are pinned to the specific version of `renode_bus.cpp` shipped with this repository. If you upgrade the IntegrationLibrary, verify that these declarations still appear at the same line numbers, or adjust accordingly.

**Verification:** Before the fix, running `nm renode_bus.o | grep handle` shows mangled undefined symbols with `U _Z17handleMainMessagePv`. After the fix, the same command shows `U handleMainMessage` — unmangled, and therefore resolvable against `dpi_stubs.o`.

---

