#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * add_dnodeint - Entry Point
 * @head: variable
 * @n: variable
 * Return: 0
 */

sttack_t push_t(sttack_t **head, const int n, int line_number)
{
    sttack_t *nuevo_nodo;
    nuevo_nodo = add_node(n);
    if (nuevo_nodo != NULL)
    {
        nuevo_nodo->next = *head;
        nuevo_nodo->prev = NULL;
        if (*head != NULL)
        {
            (*head)->prev = nuevo_nodo;
        }
        *head = nuevo_nodo;
        return (nuevo_nodo);
    }
    fprintf(stderr, "L%d: usage: push integer\n", line_number);
    return (0);
}

/**
 * crear_nodo - Entry Point
 * @n: variable
 * Return: 0
 */

sttack_t *add_node(int n)
{
    sttack_t *nuevo_nodo;
    nuevo_nodo = malloc(sizeof(sttack_t));

    if (nuevo_nodo != NULL)
    {
        nuevo_nodo->n = n;
        nuevo_nodo->next = NULL;
        nuevo_nodo->prev = NULL;
    }
    return (nuevo_nodo);
}

/**
 * print_dlistint - Entry Point
 * @h: variable head
 * Return: 0
 */

sttack_t pall_t(const sttack_t *h, int line_number)
{

    size_t i;

    i = 0;
    (void)line_number;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
        i++;
    }
}

/*void pint(stack_t *h, int line_number)
{
    if (h == NULL)
    {
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", h->n);
}

int pop(sttack_t **head)
{
    int n;
    sttack_t *new_nodo;

    if (head == NULL || *head == NULL)
    {
        return (0);
    }
    new_nodo = *head;
    *head = new_nodo->next;
    n = new_nodo->n;
    free(new_nodo);
    return (n);
}

void swap_nodes(stack_t **head, unsigned int line_number)
{
    stack_t *tmp;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        printf("%d", line_number);
    tmp = (*head)->next;
    (*head)->next = tmp->next;
    if (tmp->next != NULL)
        tmp->next->prev = *head;
    tmp->next = *head;
    (*head)->prev = tmp;
    tmp->prev = NULL;
    *head = tmp;
}

void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

int main(void)
{

    sttack_t *head;
    sttack_t *n1, *n2;

    head = NULL;
    n1 = push(&head, 1);
    n2 = push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 98);
    push(&head, 402);
    push(&head, 1024);
    pop(&head);
    pall(head);
    swap(n1, n2);

    return (EXIT_SUCCESS);
}
*/