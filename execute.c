#include "monty.h"

/**
 * executeInstruction - Executes the instruction associated with the opcode.
 * @content: Line content
 * @stack: Pointer to the head of the linked list (stack)
 * @counter: Line counter
 * @file: Pointer to the Monty file
 * Return: 0 on success, 1 on failure
 */
int executeInstruction(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t instructions[] = {
        {"push", pushStack}, {"pall", printAllStack}, {"pint", printTopStack},
        {"pop", popStack},
        {"swap", swapStackElements},
        {"add", addToStack}, {"nop", noOperation},
        {"sub", subtractFromStack},
        {"div", divideStackElements}, {"mul", multiplyStackElements},
        {"mod", modStackElements}, {"pchar", printCharFromStack},
        {"pstr", printStringFromStack},
        {"rotl", rotateStackLeft},
        {"rotr", rotateStackRight},
        {"queue", switchToQueueMode},
        {"stack", switchToStackMode},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");
    if (opcode && opcode[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    while (instructions[i].opcode && opcode)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (opcode && instructions[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free(content);
        freeStack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}
