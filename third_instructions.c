#include "monty.h"

/**
 * _mul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */

void _mul(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", cline);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	_pop(doubly, cline);
}

/**
 * _mod - computes the rest of the division of the second element
 * by the top element of the stack
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _mod(stack_t **doubly, unsigned int cline)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", cline);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", cline);
		free_glovar();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}


/**
 * _rotl - rotates the first element to the bottom and  the second to the top
 *
 * @doubly: head of the linked list
 * @cline: line number;
 * Return: no return
 */
void _rotl(stack_t **doubly, unsigned int cline)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}

/**
 * _rotr - reverse the stack
 *
 * @doubly: head of the linked list
 * @cline: line number
 * Return: no return
 */
void _rotr(stack_t **doubly, unsigned int cline)
{
	stack_t *aux = NULL;
	(void)cline;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux = *doubly;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
