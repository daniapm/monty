#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
#include "monty.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 * @argc: num arguments
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 1;
	sttack_t *stack = NULL;
	char **result = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file");
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		/*printf("Retrieved line of length %zd:\n", nread);*/

		line[nread - 1] = '\0';
		(*result) = tok_s(line);

		op_struck(&stack, line_number, result);
		line_number++;
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
