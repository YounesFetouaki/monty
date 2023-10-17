#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->next;
    (*stack)->next = temp->next;
    temp->next = *stack;
    (*stack)->prev = temp;
    temp->prev = NULL;
    *stack = temp;
}
