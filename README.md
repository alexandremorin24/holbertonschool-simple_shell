# Simple Shell

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Flowchart](#flowchart)
- [File Structure](#file-structure)
- [Man page](#man-page)
- [Examples](#examples)
- [Licence](#License)
- [Authors](#authors)

## Description

`simple_shell` is an implementation of a minimalistic shell written in C. This project was developed as part of a system programming course. It offers basic functionality for executing Unix commands via a command-line interface. In fact, simple_shell is a program that takes input commands, verifies their existence, and executes them. This simple shell works in interactive mode and non-interactive mode. 

## Features

- **Execute system commands**: The shell can execute basic Unix commands like `ls`, `pwd`, `echo`, etc.
- **Command search**: The shell searches for commands in directories specified by the `PATH` environment variable.
- **Handle environment variables**: The shell can read and use the `PATH` variable to find executable files.
- **Support for absolute and relative paths**: Commands can be executed using their absolute path (e.g., `/bin/ls`) or just the command name if it is found in the `PATH`.
- **Error handling**: Displays error messages when a command is not found or is not executable.
- **Built-in exit command**: Allows the user to exit the shell.
- **Built-in env command**: Prints the current environment variables to the standard output.

## Requirements

All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
This project uses the C standard libraries.

## Installation

To compile and run `simple_shell`, you need to have a C compiler (such as `gcc`) installed on your system.
### Clone the repository
If you haven't already, clone the repository to your local machine:
```bash
git clone https://github.com/alexandremorin24/holbertonschool-simple_shell
```
Then :
```bash
cd simple_shell
```
### Compilation
To compile the program, use `gcc`:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
### Usage
After compiling the project, you can run the shell by executing the following command in interactive mode:
```bash
./hsh
```
Otherwise you can run the shell in non-interactive mode, for example:
```bash
echo "pwd" | ./hsh
```
The shell will display a prompt (#cisfun$) and wait for user input. You can enter commands to execute them.
### Exiting the shell
To exit the shell, you can type the exit command:
```bash
exit
```

## Flowchart


## File Structure

The project consists of the following files:

- `shell.c` - The main file containing the shell loop and execution logic.
- `shell.h` - The header file containing function declarations and necessary includes.
- `split_line.c` - Contains the function for splitting input into tokens.
- `find_command.c` - Contains the function for finding the command in the PATH.
- `execute.c` - Contains the function for executing commands.
- `process_command.c` - Contains the `process_command` function for processing and executing commands.
- `input.c` - Contains the function for reading input from the user.
- `_getenv.c` - Contains the function for retrieving environment variables.
- `built_in.c` - Contains the functions for built-in commands like `exit` and `env`.
- `helpers.c` - Contains helper functions such as `_realloc` and `print_env`.
- `man_1_simple_shell` - The manual page for the project (for man command).
- `README.md` - This documentation file.

## Man page

Please visit this page:
https://github.com/alexandremorin24/holbertonschool-simple_shell/blob/main/man_1_simple_shell

## Examples

### Example 1: Listing files in the current directory
```bash
#cisfun$ ls -l
total 176
-rw-r--r--@ 1 root  staff      8  4 jan 11:07 AUTHORS
drwxr-xr-x@ 5 root  staff    160  6 jan 09:41 Concept
-rw-r--r--@ 1 root  staff   4392  8 jan 09:19 README.md
-rw-r--r--@ 1 root  staff    509  7 jan 13:24 _getenv.c
-rw-r--r--@ 1 root  staff    491  8 jan 09:14 built_in.c
-rw-r--r--@ 1 root  staff    597  7 jan 12:59 execute.c
-rw-r--r--@ 1 root  staff   1614  7 jan 14:01 find_command.c
-rw-r--r--@ 1 root  staff   1767  8 jan 09:15 helpers.c
-rwxr-xr-x@ 1 root  staff  34944  8 jan 09:27 hsh
-rw-r--r--@ 1 root  staff   1362  7 jan 20:34 input.c
-rw-r--r--@ 1 root  staff   2544  7 jan 20:34 man_1_simple_shell
-rw-r--r--@ 1 root  staff    778  8 jan 09:15 process_command.c
-rw-r--r--@ 1 root  staff    779  7 jan 13:05 shell.c
-rw-r--r--@ 1 root  staff    687  8 jan 09:14 shell.h
```
### Example 2: Running a command with an absolute path
```bash
#cisfun$ /bin/echo "Hello, World"
"Hello, World"
```
### Example 3: Command not found
```bash
#cisfun$ nonexistent_command
Error: Command 'nonexistent_command' not found in PATH
Command not found: nonexistent_command
```

## Authors
- Alexxandre MORIN
- Nicolas LASSOUANE

More informations or contact in this page :
https://github.com/alexandremorin24/holbertonschool-simple_shell/blob/main/AUTHORS

## Licence
This programm is open source and therefore free to download and use without permission.