# Redis from Scratch

[WIP] Redis-inspired in-memory key-value store built from scratch in C++, exploring TCP networking, event-driven I/O, concurrency, and data structures.

## Overview

This project explores the fundamentals of systems programming and database internals by implementing a simplified Redis-like server from scratch.

Built while following the [Build Your Own Redis](https://build-your-own.org/redis/) guide.

## Tech Stack

- **Language:** C++20
- **Networking:** POSIX sockets, TCP/IP
- **Development:** Git, GCC/Clang

## Features

**Currently implemented:**

- TCP socket creation and binding
- Listening for and accepting client connections
- Basic request-response communication using `read()` and `write()`
- Socket error handling and resource cleanup

**Planned:**

- Multiple client connections
- Custom request-response protocol
- Key-value operations (`GET`, `SET`, `DEL`)
- Custom hash table
- Event-driven I/O
- Key expiration (TTL)
- Concurrent processing

## Getting Started

### Build

```bash
g++ -std=c++20 -Wall -Wextra server.cpp -o server
```

### Run

```bash
./server
```

### Test

In another terminal, connect using Netcat:

```bash
nc 127.0.0.1 1234
```

Send a message to receive a response from the server.

## Project Status

🚧 **Work in Progress** — Basic TCP communication implemented. More features coming as development progresses.

## Acknowledgments

Based on the [Build Your Own Redis](https://build-your-own.org/redis/) tutorial.
