#include "monty.h"

/**
 * free_stack - Entry Point
 * @head: variable
 * Return: 0
 */

void free_stack(sttack_t *head)
{
	sttack_t *new;

	while (head)
	{
		new = head;
		head = head->next;
		free(new);
	}
}
