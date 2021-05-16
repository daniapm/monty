#include "monty.h"
/**
 * op_struck - Entry Point
 * @stack: variable
 * @line_number: variable
 * @opcode: variable
 * Return: 1
 */
void op_struck(sttack_t **stack, unsigned int line_number, char **opcode)
{
	int i = 0, j = 0;

	instruction_t func_list[] = {
		{"push", push_t},
		{"pall", pall_t},
		{"pint", pint_t},
		{"pop", pop_t},
		{"swap", swap_nodes},
		{"nop", nop_t},
		{NULL, NULL}};

	if (strcmp(opcode[0], "$") == 0)
		return;
	while (func_list[i].opcode != NULL)
	{
		if (strcmp(opcode[0], func_list[i].opcode) == 0)
		{
			if (strcmp(opcode[0], "push") == 0)
			{
				if (opcode[1] == NULL || (is_number(opcode[1]) == 0))
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				if (opcode[1][0] == '-')
					opcode[1]++;
				j = atoi(opcode[1]);
				variable_global.dato = j;
			}
			func_list[i].f(stack, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, opcode[0]);
	exit(EXIT_FAILURE);
}
