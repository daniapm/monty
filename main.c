#include "monty.h"

/**
 * main - Entry Point
 * @argc: num arguments
 * @argv: arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL, **result = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int line_number = 1;
	sttack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((nread = getline(&line, &len, stream)) != -1)
	{
		if (count_words(line) == 0)
		{
			line_number++;
			continue;
		}

		line[nread - 1] = '\0';
		line_number++;
		result = tok_s(line);
		op_struck(&stack, line_number, result);
	}
	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
}
