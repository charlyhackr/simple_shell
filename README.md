# Carlos y Diego's Shell

![Julien Barbi alias mr Barbier](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg)

---
### Description
Diego y Carlos's Shell is a simple UNIX command interpreter that replicates funtionalities of the simple shell. Additional functions are also included. THis program was written entirely in C as a project for HOlberton School.

### Installation
Clone this repository into your pc. For best results, files should be compiled with gcc and the following flags: -Wall -Wextra -Werror -pedantic -Wno-format.

### Usage
After compilation, the resulting program can run stand-alone either in interactive or non-interactive mode.

#### Interactive Mode
In interactive mode, simply run the program and wait for the prompt to appear. From there, you can type commands freely, exiting with either the "exit" command or ctrl-D.

#### Non-Interactive Mode
In non-interactive mode, echo your desired command and pipe it into the program like this:
```sh
echo "ls" | ./shell
```
In non-interactive mode, the program will exit after finishing your desired command(s).

### Credits
All code written by
[Diego Vivas](https://github.com/diegovivas)
[Carlos Alvarez](https://github.com/charlyhackr/)