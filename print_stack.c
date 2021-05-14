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
