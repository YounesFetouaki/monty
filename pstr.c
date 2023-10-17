#include "monty.h"

/**
 * pstr - Prints a string starting at the top of the stack.
 * @stack: Double pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;
    
    /*Silence the unused parameter warning*/
    (void)line_number;
    
    while (current && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        printf("%c", current->n);
        current = current->next;
    }
    
    printf("\n");
}
