#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* PATH Shell Functions */

/* Program Flow */

int main(void);
/*This is the main function of the program.*/

int prompt(void);
/*This function is used to print the prompt.*/

char *_read(void);
/*This function is used to read the input from the user.*/

char *_fullpathbuffer(char **av, char *PATH, char *copy);
/*This function is used to concatenate the strings.*/

int checkbuiltins(char **av, char *buffer, int exitstatus);
/*This function is used to check the builtin commands.*/

int _forkprocess(char **av, char *buffer, char *fullpathbuffer);
/*This function is used to fork the process.*/

/* String Helper Functions */

char *_strdup(char *str);
/*Duplicating the string.*/

int _splitstring(char *str);
/*This function is used to count the number of words in a string.*/

int _strcmp(const char *s1, const char *s2);
/*Compares two strings.*/

char *_strcat(char *dest, char *src);
/*This function is concatenating two strings.*/

int _strlen(char *s);
/*This function is used to count the number of characters in a string.*/

/*Tokenize & PATH Helper Functions*/

char **tokenize(char *buffer);
/*This function is tokenizing the string.*/

int _splitPATH(char *str);
/*This function is used to count the number of words in a string.*/

int _PATHstrcmp(const char *s1, const char *s2);
/*This function is comparing two strings.*/

char *_concat(char *tmp, char **av, char *tok);
/*This function is concatenating the strings.*/

/*Other Helper Funcs*/

char *_getenv(const char *name);
/*This function is used to get the value of an environment variable.*/

int _env(void);
/*This function is used to print the environment variables.*/

void _puts(char *str);
/*This function is used to print the string.*/

int _putchar(char c);
/*This function is used to print the character.*/

char *_memset(char *s, char b, unsigned int n);
/*This function is used to fill the first n bytes of*/
/*the memory area pointed to by s with the constant byte b.*/

#endif /* SHELL_H */
