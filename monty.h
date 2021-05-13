#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} sttack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

sttack_t push_t(sttack_t **head, const int n, int line_number);
sttack_t *add_node(int n);
sttack_t pall_t(const sttack_t *h, int line_number);
int pop(sttack_t **head);
void swap(sttack_t *x, sttack_t *y);
/*int tok_s(char *line);*/
void op_struck(stack_t **stack, unsigned int line_number, char *opcode);

#endif
