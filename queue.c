#include "monty.h"
/**
 * switchToQueueMode - Switches the stack mode to queue mode.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void switchToQueueMode(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addToQueue - Adds a node to the tail of the stack (queue mode).
 * @value: New value
 * @head: Head of the stack
 * Return: No return
 */
void addToQueue(stack_t **head, int value)
{
    stack_t *newNode, *current;

    current = *head;
    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        printf("Error\n");
    }
    newNode->n = value;
    newNode->next = NULL;
    if (current)
    {
        while (current->next)
            current = current->next;
    }
    if (!current)
    {
        *head = newNode;
        newNode->prev = NULL;
    }
    else
    {
        current->next = newNode;
        newNode->prev = current;
    }
}
