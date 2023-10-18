#include "monty.h"
/**
 * printCharFromStack - Prints the character at the top of the stack,
 * followed by a new line.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void printCharFromStack(stack_t **head, unsigned int counter)
{
    stack_t *current;

    current = *head;

    if (!current)
    {
        fprintf(stderr, "L%d: can't print char, stack empty\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    if (current->n > 127 || current->n < 0)
    {
        fprintf(stderr, "L%d: can't print char, value out of range\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", current->n);
}
