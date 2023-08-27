#include "monty.h"

/**
 *add_dnodeint_end - add node at the end of the doubly link list
 *@head: start node of linked list
 *@n: data to be stored
 *Return: a doubly linked list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *auxil;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glovar();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	/*Careful with the first time*/
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	auxil = *head;
	while (auxil->next)
		auxil = auxil->next;
	temp->next = auxil->next;
	temp->prev = auxil;
	auxil->next = temp;
	return (auxil->next);
}

/**
 *add_dnodeint - add node at the begining of the doubly link list
 *@head: start of linked list
 *@n: data to be stored
 *Return: a doubly linked list
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glovar();
		exit(EXIT_FAILURE);
	}
	temp->n = n;

	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_dlistint - function to free the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */
void free_dlistint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
