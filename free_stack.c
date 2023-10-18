#include "monty.h"
/**
 * freeStack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 */
void freeStack(stack_t *head)
{
    stack_t *currentNode;

    currentNode = head;
    while (head)
    {
        currentNode = head->next;
        free(head);
        head = currentNode;
    }
}
