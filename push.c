#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int n;

    arg = strtok(NULL, " \t\n");
    if (!arg || !is_integer(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    if (!push_stack(stack, n))
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * is_integer - Checks if a string represents an integer.
 * @str: The string to check.
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(char *str)
{
    int i = 0;
    if (str[0] == '-')
        i = 1;
    for (; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}
#include "monty.h"

/**
 * push_stack - Pushes a new element onto the stack.
 * @stack: Double pointer to the stack (top of the stack).
 * @n: The integer value to push onto the stack.
 * Return: 1 on success, 0 on failure (e.g., memory allocation failure).
 */
int push_stack(stack_t **stack, int n)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL) {
        return 0; /* Memory allocation failure*/
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL) {
        (*stack)->prev = new_node;
    }

    *stack = new_node;

    return 1; /* Success*/
}
