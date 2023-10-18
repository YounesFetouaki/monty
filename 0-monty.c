#include "monty.h"

/**
 * free_stack - Frees the memory allocated for the stack.
 * @stack: Pointer to the top of the stack (doubly linked list).
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/**
 * get_instruction - Gets the instruction function associated with an opcode.
 * @opcode: The opcode for which to retrieve the instruction function.
 *
 * Return: The instruction function associated with the opcode, or NULL if the
 * opcode is not found.
 */
instruction_t get_instruction(char *opcode)
{
	int i = 0;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}};
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i]);
		i++;
	}

	return (instructions[i]);
}

/**
 * execute_instruction - Executes the instruction function for a given opcode.
 * @instruction: The instruction function to execute.
 * @stack: Double pointer to the stack (doubly linked list).
 * @line_number: Line number where the opcode is encountered.
 */
void execute_instruction(instruction_t instruction,
		stack_t **stack, unsigned int line_number)
{
	instruction.f(stack, line_number);
}
