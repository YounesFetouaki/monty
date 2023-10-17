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
        dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    if (!push_stack(stack, n))
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
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
