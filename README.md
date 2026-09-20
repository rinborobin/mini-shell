# mshell

A small Unix shell written in C++ for Linux.

This project is built from scratch to learn how shells work and to get hands-on experience with Linux process management and system calls.

## Features

- Interactive command prompt
- Command and argument parsing
- External command execution
- Built-in commands
- Process creation with `fork()`
- Program execution with `execvp()`
- Process synchronization with `waitpid()`

## Roadmap

- [ ] Environment variables
- [ ] Input/output redirection
- [ ] Pipes
- [ ] Background processes
- [ ] Signal handling
- [ ] Job control
- [ ] Improved parser
- [ ] Quoting and escaping

## Build

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/mshell
```

## Requirements

- Linux
- C++20 compatible compiler
- CMake 3.20+

## Structure

```text
mshell/
├── include/
├── src/
├── tests/
├── docs/
├── CMakeLists.txt
└── README.md
```

## Status

Work in progress.
