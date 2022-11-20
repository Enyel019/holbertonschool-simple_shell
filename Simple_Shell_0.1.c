#include "shell.h"

/**
 * _getenv - It loops through the environment variables
 * and if it finds a match
 * it returns the pointer to the environment variable
 * @name: The name of the environment variable to get.
 * Return: The value of the environment variable name.
 */
char *_getenv(const char *name)
{
	int i, result;
	/* Looping through the environment variables,and if it finds a match,*/
	/* it returns the pointer to the environment variable */
	for (i = 0; environ[i]; i++)
	{
		result = _PATHstrcmp(name, environ[i]);
		if (result == 0)
		{
			return (environ[i]);
		}
	}
	return (NULL);
}
/**
 * _env - It prints the environment
 * Return: The number of characters printed.
 */
int _env(void)
{
	int i;
	/* Looping through the environment variables, and if it finds a match,*/
	/*it returns the pointer to the environment variable */
	for (i = 0; environ[i]; i++)
		_puts(environ[i]);
	return (0);
}

/**
 * _puts - It takes a string and prints it to the standard output
 * @str: This is the string that will be printed.
 * Return: Always Succes
 */
void _puts(char *str)
{
	int c;

	for (c = 0; str[c] != '\0'; c++)
		_putchar(str[c]);
	_putchar('\n');
}
/**
 * _putchar - It writes a character to the standard output
 * @c: The character to print
 * Return: the value of write.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _memset - It takes a pointer to a char, a char, and an unsigned int,
 * and returns a pointer to a char
 * @s: pointer to the memory area to be filled
 * @b: the character to fill the memory with
 * @n: number of bytes to fill
 * Return: A pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
