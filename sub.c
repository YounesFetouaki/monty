#include "monty.h"
/**
 * subtractFromStack - Subtracts the top element from the next element in the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void subtractFromStack(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int difference, nodeCount;

    current = *head;
    for (nodeCount = 0; current != NULL; nodeCount++)
        current = current->next;

    if (nodeCount < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    difference = current->next->n - current->n;
    current->next->n = difference;
    *head = current->next;
    free(current);
}
