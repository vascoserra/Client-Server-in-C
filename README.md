# Signal and Client-Server Communication in C

This project demonstrates the use of signals and client-server communication in C. It includes examples of handling signals, setting up a basic client-server architecture, and combining these concepts to create a robust networked application.

## Table of Contents

1. [Project Overview](#project-overview)
2. [Prerequisites](#prerequisites)
3. [Installation](#installation)
4. [Usage](#usage)
5. [Project Structure](#project-structure)
6. [Key Concepts](#key-concepts)
7. [Contributing](#contributing)
8. [License](#license)

## Project Overview

This project aims to explore and implement:

- Signal handling in C
- Basic client-server communication using sockets
- Combining signals with networked applications

The server component will listen for client connections and handle various signals, while the client will be able to send requests and receive responses.

## Prerequisites

- GCC compiler
- POSIX-compliant operating system (Linux, macOS, etc.)
- Basic knowledge of C programming
- Familiarity with terminal/command-line interface

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/signal-client-server-c.git
   cd signal-client-server-c
   ```

2. Compile the project:
   ```
   make
   ```

## Usage

1. Start the server:
   ```
   ./server
   ```

2. In a separate terminal, run the client:
   ```
   ./client
   ```

3. Follow the on-screen prompts to interact with the server and test signal handling.

## Project Structure

```
signal-client-server-c/
├── src/
│   ├── server.c
│   ├── client.c
│   └── common.h
├── Makefile
├── README.md
└── LICENSE
```

## Key Concepts

1. **Signal Handling**: The project demonstrates how to set up signal handlers using `sigaction()` to manage various signals like SIGINT, SIGTERM, etc.

2. **Socket Programming**: Basic socket operations are implemented to establish client-server communication.

3. **Client-Server Architecture**: The project shows a simple implementation of the client-server model, with the server handling multiple client connections.

4. **Combining Signals and Networking**: The server uses signals to gracefully handle shutdown requests and other events while maintaining client connections.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.