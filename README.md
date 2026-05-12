# Ninbot

Ninbot is a small terminal-based assistant written in C for Linux systems.

The project is focused on learning:
- low-level programming
- command parsing
- file handling
- modular software structure
- Linux system interaction

Rather than relying heavily on built-in abstractions, Ninbot intentionally implements many systems manually to better understand how software works internally.

---

# Features

## Current Features

- Terminal-based assistant interface
- Random startup greetings
- Command parsing system
- YouTube search integration
- Current time and date display
- Persistent user setup system
- Todo management system
- Modular source structure
- Linux browser launching using `xdg-open`

---

# First Time Setup

When Ninbot runs for the first time, it checks for a user data file.

If no data exists:
- Ninbot asks for your name
- creates a persistent data file
- stores user information locally

On future launches, Ninbot automatically loads the saved data and uses it during runtime.

---

# Commands

| Command | Description |
|---|---|
| `youtube` | Opens YouTube homepage |
| `youtube <search>` | Searches YouTube |
| `time` | Displays current time and date |
| `todo add <task>` | Adds a todo item |
| `todo show` | Displays all todo items |
| `todo remove <number>` | Removes a todo item |
| `help` | Shows available commands |
| `meow` | Secret command |
| `exit` | Exits Ninbot |

---

# Todo System

Todos are stored persistently inside:

```text
todo.txt
```

Example:

```text
Buy groceries
Finish assignment
Practice C
```

---

# User Data System

User information is stored locally using simple file-based persistence.

Example structure:

```text
name=Ninjazz
```

This system will later be expanded for:
- preferences
- aliases
- app launchers
- saved settings
- assistant memory

---

# Project Structure

```text
Ninbot/
├── data.txt
├── todo.txt
├── main.c
├── commands.c
├── commands.h
├── execute.c
├── execute.h
└── README.md
```

---

# Compilation

Compile using GCC:

```bash
gcc main.c execute.c commands.c -o ninbot
```

Run:

```bash
./ninbot
```

---

# Platform

Currently designed for Linux systems such as:
- Zorin OS
- Ubuntu
- Debian-based distributions

The project uses:

```bash
xdg-open
```

for browser-related features.

---

# Planned Features

- App launcher aliases
- Command history/log system
- File searching
- Notes system
- User-defined aliases
- Better parser architecture
- Colored terminal UI
- Plugin-like command system
- Voice interaction experiments
- Background startup mode

---

# Learning Goals

This project is mainly being built to practice:

- C programming
- String manipulation
- File I/O
- Linux process interaction
- Persistent storage systems
- Modular application design
- Command interpreters
- Terminal application architecture

---

# Notes

Ninbot is still in early development.

Many systems are intentionally written manually for learning purposes rather than using higher-level libraries or abstractions.

---

# License

This project is open-source and free to modify.
