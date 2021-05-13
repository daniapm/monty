#include "monty.h"

void op_struck(stack_t **stack, unsigned int line_number, char *opcode)
{
    int i;
    instruction_t func_list[] = {
        {"push", push_t},
        {"pall", pall_t},
        {NULL, NULL}};

    if (opcode[0] == '$')
        return;

    while (func_list[i].opcode != NULL)
    {
        if (strcmp(opcode, func_list[i].opcode) == 0)
        {
            func_list[i].f(stack, line_number);
            return;
        }
        i++;
    }

    printf("L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
