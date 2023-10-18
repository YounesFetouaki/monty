#include "monty.h"
/**
 * pushToStack - Adds a node to the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void pushToStack(stack_t **head, unsigned int counter)
{
    int number, index = 0, invalidFlag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            index++;
        for (; bus.arg[index] != '\0'; index++)
        {
            if (bus.arg[index] > '9' || bus.arg[index] < '0')
                invalidFlag = 1;
        }
        if (invalidFlag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file); // Note: "bus" is not defined in this code
            free(bus.content); // Note: "bus" is not defined in this code
            freeStack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    number = atoi(bus.arg);

    if (bus.lifi == 0)
        addNodeToStack(head, number);
    else
        addNodeToQueue(head, number);
}
