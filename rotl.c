#include "monty.h"
/**
 * rotateLeft - Rotates the stack to the top.
 * @head: Stack head
 * @counter: Line number (unused)
 * Return: No return
 */
void rotateLeft(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
    stack_t *current = *head, *newHead;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    newHead = (*head)->next;
    newHead->prev = NULL;

    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = *head;
    (*head)->next = NULL;
    (*head)->prev = current;
    (*head) = newHead;
}
