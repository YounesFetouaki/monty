#include "monty.h"
/**
 * popStackTop - Removes the top element from the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void popStackTop(stack_t **head, unsigned int counter)
{
    stack_t *current;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop from an empty stack\n", counter);
        fclose(bus.file); // Note: "bus" is not defined in this code
        free(bus.content); // Note: "bus" is not defined in this code
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    *head = current->next;
    free(current);
}
