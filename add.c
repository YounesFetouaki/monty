#include "monty.h"
/**
 * addStackTop - Adds the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void addStackTop(stack_t **head, unsigned int counter)
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
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        freeStack(*head);
        exit(EXIT_FAILURE);
    }
    current = *head;
    result = current->n + current->next->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}
