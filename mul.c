#include "monty.h"
/**
 * multiplyStackTop - Multiplies the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void multiplyStackTop(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int length = 0, result;

    current = *head;
    while (current)
    {
        current = current->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't multiply, stack too short\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    result = current->next->n * current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}
