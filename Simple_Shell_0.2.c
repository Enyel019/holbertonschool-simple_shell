#include "shell.h"
/**
 * prompt - The above function prints the prompt "$ " to the standard output.
 * Return: The prompt function returns 0.
 */
int prompt(void)
{
	char *prompt = "(Enyel,Jimmy)$ ";
	ssize_t writecount = 0;
	/* Checking if the standard input is a terminal*/
	/* and if it is, it prints the prompt. */
	if (isatty(STDIN_FILENO) == 1)
	{
		writecount = write(STDOUT_FILENO, prompt, 16);
		if (writecount == -1)
			exit(0);
	}
	return (0);
}
/**
 * _read - It reads a line from stdin, removes the newline character,
 * and returns a pointer to the string
 * Return:A pointer to the first character of a string.
 */
char *_read(void)
{
	ssize_t readcount = 0;
	size_t n = 0;
	char *buffer = NULL;
	int i = 0;

	readcount = getline(&buffer, &n, stdin);

	/* Checking if the readcount is -1, and if it is*/
	/* it frees the buffer, and if the standard input is a*/
	/* terminal, it prints a newline, and exits. */
	if (readcount == -1)
	{
		free(buffer);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	/* Checking if the last character of the buffer is a newline or a tab,*/
	/* and if it is, it replaces it*/
	/* with a null character. */
	if (buffer[readcount - 1] == '\n' || buffer[readcount - 1] == '\t')
		buffer[readcount - 1] = '\0';
	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == '#' && buffer[i - 1] == ' ')
		{
			buffer[i] = '\0';
			break;
		}
	}
	return (buffer);
}
/**
 * _fullpathbuffer - It takes the PATH environment variable,
 *  splits it into tokens, and then concatenates each token with
 * the first argument of the command line, and checks if the
 * resulting string is a valid path. If it
 * is, it returns the full path of the command
 * @av: - the array of arguments passed to the program
 * @PATH: - The environment variable PATH
 * @copy: - a copy of the PATH environment variable
 * Return:A pointer to a string.
 */
char *_fullpathbuffer(char **av, char *PATH, char *copy)
{
	char *tok, *fullpathbuffer = NULL, *concatstr = NULL;
	static char tmp[256];
	int PATHcount = 0, fullpathflag = 0, /*len = 0,*/ z = 0, toklen = 0;
	struct stat h;

	copy = NULL;
	copy = _strdup(PATH);
	PATHcount = _splitPATH(copy);
	tok = strtok(copy, ": =");
	while (tok != NULL)
	{
		concatstr = _concat(tmp, av, tok); /* Checking if the concatenated*/
		if (stat(concatstr, &h) == 0)	   /*string is a valid path. */
		{
			fullpathbuffer = concatstr;
			fullpathflag = 1;
			break;
		}
		/* Checking if the token is the last token in */
		/*the PATH environment variable. */
		if (z < PATHcount - 2)
		{
			toklen = _strlen(tok);
			if (tok[toklen + 1] == ':')
			{
				if (stat(av[0], &h) == 0)
				{
					fullpathbuffer = av[0];
					fullpathflag = 1;
					break;
				}
			}
		}
		z++;
		tok = strtok(NULL, ":");
	}
	if (fullpathflag == 0)
		fullpathbuffer = av[0];
	free(copy);
	return (fullpathbuffer);
}
/**
 * checkbuiltins - It checks if the command is a builtin,
 *  and if it is, it executes it
 * @av: array of strings, each string is a word,from the command line
 * @buffer: - The buffer that contains the command line input.
 * @exitstatus: - The exit status of the last command executed.
 * Return:the value of the exit status.
 */
int checkbuiltins(char **av, char *buffer, int exitstatus)
{
	int i;

	/* Checking if the command is env, and if it is,*/
	/*it prints the environment variables, and then it*/
	/*frees the array of strings, and the buffer, and returns 1.*/
	if (_strcmp(av[0], "env") == 0)
	{
		_env();
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		return (1);
	}
	/**
	 * It frees all the memory allocated for the command,
	 *  and then exits the shell.
	 * @_strcmp:- `av` is the array of arguments passed to the function.
	 */
	else if (_strcmp(av[0], "exit") == 0)
	{
		for (i = 0; av[i]; i++)
			free(av[i]);
		free(av);
		free(buffer);
		exit(exitstatus);
	}
	else
		return (0);
}
/**
 * _forkprocess - It forks a process, and if the child process is successful,
 *  it executes the command, and if the
 * child process fails, it prints an error message and exits
 * @av: - The array of strings that will be passed to execve.
 * @buffer: - The buffer that contains the command line input.
 * @fullpathbuffer: - The full path of the command to be executed.
 * Return:The exit status of the child process.
 */
int _forkprocess(char **av, char *buffer, char *fullpathbuffer)
{
	int i, status, result, exitstatus = 0;
	pid_t pid;

	/* Forking a process, and if the child process is successful,*/
	/*it executes the command, and if the */
	/*child process fails, it prints an error message and exits. */
	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	if (pid == 0)
	{
		result = execve(fullpathbuffer, av, environ);
		if (result == -1)
		{
			perror(av[0]);
			for (i = 0; av[i]; i++)
			free(av[i]);
			free(av);
			free(buffer);
			exit(127);
		}
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
	}
	/* Freeing the memory allocated for the command. */
	for (i = 0; av[i]; i++)
		free(av[i]);
	free(av);
	free(buffer);
	return (exitstatus);
}
