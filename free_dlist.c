#include "monty.h"

/**
 * free_dlistint - frees all nodes
 * @head: head of list
 */
void free_dlistint(stack_t **head)
{
	if (!head)
		return;

	while (*head && (*head)->next)
	{
		*head = (*head)->next;
		free((*head)->prev);
	}
	free(*head);
}
