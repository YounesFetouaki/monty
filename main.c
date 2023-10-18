#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: Number of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *lineContent;
    FILE *montyFile;
    size_t bufferSize = 0;
    ssize_t bytesRead = 1;
    stack_t *stack = NULL;
    unsigned int lineCounter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    montyFile = fopen(argv[1], "r");
    bus.file = montyFile;
    if (!montyFile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (bytesRead > 0)
    {
        lineContent = NULL;
        bytesRead = getline(&lineContent, &bufferSize, montyFile);
        bus.content = lineContent;
        lineCounter++;
        if (bytesRead > 0)
        {
            execute(lineContent, &stack, lineCounter, montyFile);
        }
        free(lineContent);
    }

    freeStack(stack);
    fclose(montyFile);
    return (0);
}
