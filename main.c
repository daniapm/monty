#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <sys/stat.h>
char *tok_s(char *line);
#include "monty.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    unsigned int line_number = 1;
    stack_t *stack;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    stream = fopen(argv[1], "r");
    if (stream == NULL)
    {
        perror("Error: Can't open file %s\n");
        exit(EXIT_FAILURE);
    }

    while ((nread = getline(&line, &len, stream)) != -1)
    {
        /*printf("Retrieved line of length %zd:\n", nread);*/

        line[nread - 1] = '\0';
        char *result = tok_s(line);
        printf("%d: ", line_number);
        printf("%s ", result);
        result = strtok(NULL, " ");
        printf("%s", result);
        printf("\n");
        op_struck(&stack, line_number, result);
        line_number++;
    }

    free(line);
    fclose(stream);
    exit(EXIT_SUCCESS);
}
