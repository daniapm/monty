#include "monty.h"

/**
 * pint_t - Entry Point
 * @head: variable head
 * @line_number: variable head
 * Return: 0
 */

void pint_t(sttack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pall_t - Entry Point
 * @h: variable head
 * @line_number: variable head
 * Return: 0
 */

void pall_t(sttack_t **h, unsigned int line_number)
{
	sttack_t *node;

	(void)line_number;
	node = *h;
	while (node)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}

/**
 * is_number - verify if the input[1] is a number.
 * @num: input[1].
 *
 * Return: 1 if true and 0 if false.
 */
int is_number(char *num)
{
	int i;

	for (i = 0; num[i] != 0; i++)
	{
		if (((num[i] > 47) && (num[i] < 58)) || num[i] == 45)
			continue;
		else
			return (0);
	}
	return (1);
}
