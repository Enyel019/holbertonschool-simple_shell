
![Logo shell](https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg) 
# simple_shell project repository

This repository contains the files for Holberton's **simple_shell**. It can be compiled using GCC and will execute a simple shell that can be used for some basic tasks and programs most commonly found in the /bin/ folder.

# Pre-requisites

### Authorized functions and macros:
- access (man 2 access)
- chdir (man 2 chdir)
- close (man 2 close)
- closedir (man 3 closedir)
- execve (man 2 execve)
- exit (man 3 exit)
- _exit (man 2 _exit)
- fflush (man 3 fflush)
- fork (man 2 fork)
- free (man 3 free)
- getcwd (man 3 getcwd)
- getline (man 3 getline)
- isatty (man 3 isatty)
- kill (man 2 kill)
- malloc (man 3 malloc)
- open (man 2 open)
- opendir (man 3 opendir)
- perror (man 3 perror)
- read (man 2 read)
- readdir (man 3 readdir)
- signal (man 2 signal)
- stat (__xstat) (man 2 stat)
- lstat (__lxstat) (man 2 lstat)
- fstat (__fxstat) (man 2 fstat)
- strtok (man 3 strtok)
- wait (man 2 wait)
- waitpid (man 2 waitpid)
- wait3 (man 2 wait3)
- wait4 (man 2 wait4)
- write (man 2 write)

### GCC command to compile:
`
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
`

This wil compile all the '.c' files and change the output's name to 'hsh'.

### Template to test output:
=============
$ ./hsh

($) 

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

RADME.md: this.

### Contact Info:
- Enyel Feliz Mercado <Enyelfm@gmail.com>
- Jimmy Hernandez Rivera <jimoem24@gmail.com>

