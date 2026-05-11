# Ninbot

Ninbot is a small terminal-based assistant written in C for Linux systems.  
The project is focused on learning low-level programming concepts, command parsing, modular project structure, and basic system automation.

Currently, Ninbot can:
- Open YouTube or search terms in the browser
- Display current system time and date
- Execute simple terminal commands
- Parse user input into commands and arguments
- Respond with simple assistant-style interactions

This project is still in early development.

---

# Features

## Current Features

- Terminal-based assistant interface
- Random startup greetings
- Command parsing system
- YouTube search integration
- Current time/date display
- Modular source structure (`main.c`, `commands.c`, `execute.c`)
- Linux browser launching using `xdg-open`

---

# Commands

|-------------------------------------------------------------------------------------|
| Command | Description 															  |
|-------------------------------------------------------------------------------------|
| `youtube` | Opens YouTube homepage 												  |
| `youtube <search>` | Searches YouTube for a term 									  |
| `time` | Displays current time and date 											  |
| `help` | Shows available commands 												  |
| `meow` | Secret command 															  |
| `todo <mode> <args>` 																  | 
|---Available mode--------------------------------------------------------------------|
| ` add ` -> Adds a task to your todo list. 										  |
| ` remove [number/all] ` -> Removes the todo at given number.  				 	  |
| ` show <number> ` -> Shows all tasks in todo list (Providing a number is optional). |
|-------------------------------------------------------------------------------------|
| `exit` | Exits Ninbot 														      |
|-------------------------------------------------------------------------------------|


---

# Project Structure

```text
Ninbot/
├── main.c
├── commands.c
├── commands.h
├── execute.c
├── execute.h
├── README.md
└── todo.txt
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

to launch browser-related commands.

---

# Future Plans

Planned features include:

- App launcher system
- File searching
- Persistent memory/config system
- Custom aliases
- User-defined commands
- Better command parsing
- Colored terminal UI
- Voice interaction experiments
- Background startup mode
- Plugin-style command architecture

---

# Learning Goals

This project is mainly being built to practice:

- C programming
- String parsing
- File handling
- Linux system interaction
- Modular code organization
- Process execution
- Terminal application design

---

# Notes

This project intentionally avoids relying heavily on built-in abstractions in order to better understand lower-level behavior and implementation details.

Some parts are experimental and may change frequently.

---

# License

This project is open-source and free to modify.