#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}
