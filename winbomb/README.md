# WinBomb

## Table of Contents
1. [System Requirements](#system-requirements)
1. [About WinBomb](#about-winbomb)
1. [Getting Started](#getting-started)
1. [Hints](#hints)
1. [Helpful Tools](#helpful-tools)

## System Requirements
- **Operating Systems:** Windows 10 or later

## About WinBomb
WinBomb is a multi-stage reverse engineering challenge designed for developers. The executable (`winbomb.exe`) contains a series of puzzles and tasks that must be solved to progress through each stage. The goal is to reverse engineer the program, understand its inner workings, and pass all stages.

## Getting Started
To begin the challenge, simply run `winbomb.exe` and follow the prompts. Each stage will provide you with a task or puzzle to solve. Your goal is to pass all stages.

## Hints
- Coming soon!

## Helpful Tools
### 1. Sysinternals Suite
- **Download Link:** [Sysinternals Suite](https://learn.microsoft.com/en-us/sysinternals/downloads/sysinternals-suite)
- **Description:** This suite includes various tools such as `strings.exe`, which can aid in analyzing binaries and system processes.
- **Installation:** Download the suite, extract the contents into a folder, then update your environment variables to include the new folder.

### 2. Environment Variables
- **Link:** [About Environment Variables](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.core/about/about_environment_variables?view=powershell-7.4)
- **Description:** Understanding and managing environment variables is crucial for accessing tools and resources efficiently during the challenge.

### 3. Ghidra
- **Download Link:** [Ghidra](https://ghidra-sre.org/)
- **Description:** Ghidra is a powerful software reverse engineering (SRE) framework developed by the National Security Agency. It assists in analyzing compiled code, which can be invaluable for dissecting `winbomb.exe`.
- **Installation:** Download Ghidra and follow the installation instructions to leverage its capabilities throughout the challenge.

### 4. Process ID (PID)
- **Link:** [Get-Process PowerShell Cmdlet](https://learn.microsoft.com/en-us/powershell/module/microsoft.powershell.management/get-process?view=powershell-7.4)
- **Description:** Learn how to retrieve the Process ID (PID) of running processes. This knowledge is essential for identifying and monitoring the execution of `winbomb.exe`.

### 5. WinDbg / Visual Studio Debugger
- **Download Link:** 
  - [WinDbg](https://docs.microsoft.com/en-us/windows-hardware/drivers/debugger/debugger-download)
  - [Visual Studio](https://visualstudio.microsoft.com/downloads/)
- **Description:** WinDbg is a versatile debugger for Windows, suitable for kernel-mode and user-mode debugging, crash dump analysis, and CPU register examination. Alternatively, Visual Studio Debugger provides an integrated development environment (IDE) with robust debugging capabilities.
