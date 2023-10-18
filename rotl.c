#include "monty.h"

/**
 * rotl - Rotates the stack to the top.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current, *new_top;

	if (*stack && (*stack)->next)
	{
		current = *stack;
		new_top = current->next;

		while (current->next)
			current = current->next;

		current->next = *stack;
		(*stack)->prev = current;
		(*stack)->next = NULL;
		new_top->prev = NULL;
		*stack = new_top;
	}

	(void)line_number;
	/* Unused parameter; silence compiler warning*/
}
