#include "monty.h"
/**
 * divideStackTop - Divides the top two elements of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void divideStackTop(stack_t **head, unsigned int counter)
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
        fprintf(stderr, "L%d: can't divide, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        freeStack(*head);
        exit(EXIT_FAILURE);
    }

    result = current->next->n / current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}
