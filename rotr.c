#include "monty.h"

/**
 * rotr - Rotates the stack to the bottom.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_bottom;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		new_bottom = current;

		while (current->next)
			current = current->next;

		current->next = *stack;
		(*stack)->prev = current;
		(*stack)->next = NULL;
		new_bottom->prev = NULL;
		*stack = current;
	}

	(void)line_number;
	/* Unused parameter; silence compiler warning*/
}
