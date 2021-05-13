#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>

char *tok_s(char *line)
{

	char *operations;

	if (line == NULL)
		return (0);

	operations = strtok(line, " ");
	if (operations == NULL)
		return (0);

	return (operations);
}
