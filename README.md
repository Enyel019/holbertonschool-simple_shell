
![Logo shell](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg) 
# Simple_Shell project repository
Description:

The "Simple Shell" project is an implementation of a basic yet functional Command-Line Interface (CLI). Inspired by Unix systems, this shell provides users with a straightforward way to interact with their operating system. With intuitive commands and the ability to execute programs, the "Simple Shell" is a versatile tool for managing and automating tasks on Unix-based systems.

## Key Features:

### Intuitive Interface:
Designed to be easy to understand and use, even for novice users.

### Command Execution: 
Allows for the execution of system commands and external programs.

### Process Management:
Offers basic process management capabilities, such as background execution and switching between processes.

### Support for Redirection and Pipes:
Enables manipulation of input and output streams for task automation.

### Custom Functions:
Potential for adding custom commands and functionalities.

This repository contains the files for Holberton's **simple_shell**. It can be compiled using GCC and will execute a simple shell that can be used for some basic tasks and programs most commonly found in the /bin/ folder.

## How To Use?
Clone The Repo

`https://github.com/Enyel019/holbertonschool-simple_shell.git
`

### GCC command to compile:
`
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
`

This wil compile all the '.c' files and change the output's name to 'hsh'.

### Template to test output:
`
$ ./hsh
`

`
($)
`

hsh main.c shell.c

$ exit
$


After you clone this repository and compile the program with the command above, you will generate a file called **hsh** that can be executed by entering  ```./hsh``` in your shell.

The output after the program is executed should look something like this:
```
$|
```
Where you will get a prompt in the shape of a dollar sign so you can start typing commands into your shell.  Agood example of how it should execute is the command shown above were the user enters 'ls' and then gets a list of the directory contents.
## Function Prototypes:

Brief description of functions contained in project:

### Program Flow

- `int main(void);` This is the main function of the program.
- `int prompt(void);` This function is used to print the prompt.
- `char *_read(void)` This function is used to read the input from the user.
- `char *_fullpathbuffer(char **av, char *PATH, char *copy);` This function is used to concatenate the strings.
- `int checkbuiltins(char **av, char *buffer, int exitstatus);` This function is used to check the builtin commands.
- `int _forkprocess(char **av, char *buffer, char *fullpathbuffer);` This function is used to fork the process.

### String Helper Functions

- `char *_strdup(char *str);` Duplicating the string.
- `int _splitstring(char *str);` This function is used to count the number of words in a string.
- `int _strcmp(const char *s1, const char *s2);` Compares two strings.
- `char *_strcat(char *dest, char *src);` This function is concatenating two strings.
- `int _strlen(char *s);` This function is used to count the number of characters in a string.

### Tokenize & PATH Helper Functions

- `char **tokenize(char *buffer);` This function is tokenizing the string.
- `int _splitPATH(char *str);`This function is used to count the number of words in a string.
- `int _PATHstrcmp(const char *s1, const char *s2);` This function is comparing two strings.
- `char *_concat(char *tmp, char **av, char *tok);` his function is concatenating the strings.

### Other Helper Funcs

- `char *_getenv(const char *name);`This function is used to get the value of an environment variable.
- `int _env(void);` This function is used to print the environment variables.
- `void _puts(char *str);` This function is used to print the string.
- `int _putchar(char c);` This function is used to print the character.
- `char *_memset(char *s, char b, unsigned int n);` This function is used to fill the first n bytes of the memory area pointed 
to by s with the constant byte b.


# Simple Shell Flowchart
![Flowchart Shell](https://miro.medium.com/max/640/1*nR6GwCthQTJxkpH_EFmWTA.webp) 

### Contact Info:
- Enyel Feliz Mercado <Enyelfm@gmail.com>
- Jimmy Hernandez Rivera <jimoem24@gmail.com>

