#include "monty.h"

/**
 * set_stack_mode - Sets the data structure mode to stack (LIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void set_stack_mode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* Nothing to do here, as stack mode is the default behavior.*/
}

/**
 * set_queue_mode - Sets the data structure mode to queue (FIFO).
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	/* If the stack is not empty and has more than one element,*/
	/* reverse the order of elements to change to queue mode.*/
	if (current && current->next)
	{
		stack_t *prev = NULL;
		stack_t *next = NULL;

		while (current)
		{
			next = current->next;
			current->next = prev;
			current->prev = next;
			prev = current;
			current = next;
		}

		*stack = prev; /* Update the stack pointer.*/
	}
}
