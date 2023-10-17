#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack as an ASCII character.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n < 0 || (*stack)->n > 127) // Check if the value is out of the ASCII range
    {
        dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", (*stack)->n);
}
