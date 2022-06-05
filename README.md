# pipex_42
Is it about the pipe?

## About
The **"pipex"** is an implementation of a small part of the SHELL terminal functionality.

More specifically, in this project we manipulate file descriptors and generate processes to write and read from the pipe.

This allows us, for example, to write the result of the first command with **file1** to one end of the pipe, then read it from the other end of the pipe and 

apply it with another command to **file223213** for example

## Compilation

make all - compile

make re - recompile

make fclean \ clean - clean
***
## Run

Use for example "./pipex "ls -la" file1 cat file223213" to start the script.

***
@SSenpo
