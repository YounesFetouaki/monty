#include "monty.h"
/**
 * printTopValue - Prints the top value of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void printTopValue(stack_t **head, unsigned int counter)
{
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't print top value, stack empty\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*head)->n);
}
