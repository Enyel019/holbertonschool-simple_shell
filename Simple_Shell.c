#include "shell.h"

/**
 * main - the entry point that runs the shell program.
 * Return: 0 on success
 */
int main(void)
{
	char *fullpathbuffer = NULL, *copy = NULL, *buffer = NULL;
	char *PATH = NULL, **av;
	int exitstatus = 0;

	/* This is setting up the shell to ignore the SIGINT signal. */
	signal(SIGINT, SIG_IGN);

	/* Getting the PATH environment variable. */
	PATH = _getenv("PATH");
	if (PATH == NULL)
		return (-1);

	/*It will prompt the user for input, read the input, 
	tokenize the input, check for builtins, and fork a 
	process to execute the command. */
	while (1)
	{
		av = NULL;
		prompt();
		buffer = _read();
		if (*buffer != '\0')
		{
			av = tokenize(buffer);
			if (av == NULL)
			{
				free(buffer);
				continue;
			}
			/* This is checking for builtins, and if there are none, 
			it will fork a process to execute the command. */
			fullpathbuffer = _fullpathbuffer(av, PATH, copy);
			if (checkbuiltins(av, buffer, exitstatus) == 1)
				continue;
			exitstatus = _forkprocess(av, buffer, fullpathbuffer);
		}
		else
			free(buffer);
	}
	return (0);
}
