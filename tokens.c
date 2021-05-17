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

/**
 * tok_s - simple shell command tokenizer
 * @command: passed commands
 * Return: char double pointer
 */
char **tok_s(char *command)
{
	int position = 0;
	char *token = NULL;
	char **tokens = NULL;
	/*allocate memory to pointer tokens*/
	tokens = malloc((count_words(command) + 1) * sizeof(char *));

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*imprimir errores de memoria*/

	/* pointer receiving tokenized command*/

	token = strtok(command, " \n\t\a");

	/*as long as tokens is different from null it makes a copy of token in token*/
	while (token != NULL)
	{

		tokens[position] = strdup(token);
		/*end in null*/
		token = strtok(NULL, " \n\t\a");
		position++;
	}
	tokens[position] = NULL;
	return (tokens);
}

/**
 * count_words - function that counts words
 * @string: sentence containing the words to count
 * main - Return
 * Return: void
 */

int count_words(char *string)
{
	int state = 0;
	unsigned int contar = 0;

	while (*string)
	{

		if (*string == ' ' || *string == '\n' || *string == '\t')
			state = 0;

		else if (state == 0)
		{
			state = 1;
			++contar;
		}
		++string;
	}
	return (contar);
}
