#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack (doubly linked list).
 * @line_number: Line number where the push opcode is encountered.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *argument = strtok(NULL, " \t\n");
	int number = atoi(argument);
	stack_t *new_element = malloc(sizeof(stack_t));

	if (argument == NULL || !argument[0])
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (number == 0 && argument[0] != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (new_element == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_element->n = number;
	new_element->prev = NULL;
	new_element->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_element;

	*stack = new_element;
}
