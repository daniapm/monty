#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push_t - Entry Point
 * @head: variable
 * @line_number: variable
 * Return: 0
 */

void push_t(sttack_t **head, unsigned int line_number)
{
	sttack_t *nuevo_nodo;

	if (variable_global.dato < '0' || variable_global.dato > '9')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (*head)
		{
			sttack_t *temp;

			while (head)
			{
				temp = *head;
				*head = (*head)->next;
				free(temp);
			}
		}
		exit(EXIT_FAILURE);
	}
	nuevo_nodo = add_node(variable_global.dato);
	if (nuevo_nodo != NULL)
	{
		nuevo_nodo->next = *head;
		nuevo_nodo->prev = NULL;
		if (*head != NULL)
		{
			(*head)->prev = nuevo_nodo;
		}
		*head = nuevo_nodo;
	}
}

/**
 * add_node - Entry Point
 * @n: variable
 * Return: 0
 */

sttack_t *add_node(int n)
{
	sttack_t *nuevo_nodo;

	nuevo_nodo = malloc(sizeof(sttack_t));

	if (nuevo_nodo == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (nuevo_nodo != NULL)
	{
		nuevo_nodo->n = n;
		nuevo_nodo->next = NULL;
		nuevo_nodo->prev = NULL;
	}
	return (nuevo_nodo);
}

/**
 * pop_t - Entry Point
 * @head: variable head
 * @line_number: variable head
 * Return: 0
 */

void pop_t(sttack_t **head, unsigned int line_number)
{
	sttack_t *new_nodo;

	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		while (head != NULL)
		{
			new_nodo = *head;
			*head = (*head)->next;
			free(new_nodo);
		}
		exit(EXIT_FAILURE);
	}
	new_nodo = *head;
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	else
		*head = NULL;
	variable_global.dato = new_nodo->n;
	free(new_nodo);
}

/**
 * swap_nodes - Entry Point
 * @head: variable head
 * @line_number: variable head
 * Return: 0
 */

void swap_nodes(sttack_t **head, unsigned int line_number)
{
	sttack_t *tmp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		while (head != NULL)
		{
			tmp = *head;
			tmp = (*head)->next;
			free(tmp);
		}
		exit(EXIT_FAILURE);
	}
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *head;
	tmp->next = *head;
	(*head)->prev = tmp;
	tmp->prev = NULL;
	*head = tmp;
}

/**
 * nop_t - Entry Point
 * @stack: variable head
 * @line_number: variable head
 * Return: 0
 */

void nop_t(sttack_t **stack, unsigned int line_number)
{

	(void)stack;
	(void)line_number;
}
