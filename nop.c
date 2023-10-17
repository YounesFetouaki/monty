#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    /* The nop opcode does nothing, so just return without taking any action. */
}
