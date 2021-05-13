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
	token = strtok(command, " $\n");

	/*as long as tokens is different from null it makes a copy of token in token*/
	while (token != NULL)
	{
		tokens[position] = strdup(token);
		/*end in null*/
		token = strtok(NULL, " $\n");
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
	int cont1, cont2 = 0;

	for (cont1 = 0; string[cont1]; cont1++)
	{
		if (string[cont1] == 32 && string[cont1 + 1] != 32 && string[cont1 + 1] != 0)
			cont2++;
	}

	if (string[0] != 32)
		cont2++;

	return (cont2);
}
