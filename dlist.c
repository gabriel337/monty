#include "monty.h"

/**
 * stack_t *add_dnodeint_end - add node to the end of dlist
 * @head: head of list
 * @n: node data
 * Return: address of new node or NULL if failed
 */
int add_dnodeint_end(stack_t **head, int n)
{
	stack_t *new;

	if (!head)
		return (-1);

	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}

	new->n = n;

	if (*head == NULL)
	{
		*head = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *head;
		(*head)->prev = new;
		*head = new;
	}

	return (0);
}
