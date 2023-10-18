#include "monty.h"
/**
 * printStack - Prints the elements of the stack.
 * @head: Stack head
 * @counter: Not used
 * Return: No return
 */
void printStack(stack_t **head, unsigned int counter)
{
    stack_t *current;
    (void)counter;

    current = *head;
    if (current == NULL)
        return;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
