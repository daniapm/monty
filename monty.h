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

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(sttack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct my_struck_s - doubly linked list representation of a stack (or queue)
 * @dato: integer
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct my_struck_s
{
	int dato;
} my_struck_t;
my_struck_t variable_global;

void push_t(sttack_t **head, unsigned int line_number);
sttack_t *add_node(int n);
void pall_t(sttack_t **h, unsigned int line_number);
void pop_t(sttack_t **head, unsigned int line_number);
void swap_nodes(sttack_t **head, unsigned int line_number);
/*int tok_s(char *line);*/
void op_struck(sttack_t **stack, unsigned int line_number, char **opcode);
char **tok_s(char *command);
int count_words(char *string);
void pint_t(sttack_t **head, unsigned int line_number);
void nop_t(sttack_t **stack, unsigned int line_number);
void free_stack(sttack_t *head);

#endif
