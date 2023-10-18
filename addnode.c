#include "monty.h"
/**
 * pushToStack - Adds a new node to the head of the stack.
 * @head: Pointer to the head of the stack.
 * @n: Value to be added to the new node.
 * Return: No return value.
 */
void pushToStack(stack_t **head, int n)
{
    stack_t *newNode, *currentNode;

    currentNode = *head;
    newNode = malloc(sizeof(stack_t));

    if (newNode == NULL)
    {
        printf("Error: Unable to allocate memory for a new node.\n");
        exit(EXIT_FAILURE);
    }

    if (currentNode != NULL)
    {
        currentNode->prev = newNode;
    }

    newNode->n = n;
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}
