#include "monty.h"
/**
 * is_push- function that pushes an element to the stack
 * @head: pointer to top of stack
 * @number: number to insert to the stack
 */
void is_push(sstack_t **head, unsigned int number)
{
	sstack_t *new = NULL;

	new = malloc(sizeof(sstack_t));
	if (new == NULL)
	{
		free_dlistint(*head);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = number;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
}
/**
 * is_pall- function that prints the stack
 * @head: pointer to the top
 * @number: integer
 */
void is_pall(sstack_t **head, unsigned int number)
{
	sstack_t *tmp = *head;

	number = number;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
/**
 * is_pint- function that prints the top of the stack
 * @head: pointer of the top of the stack
 * @number: integer
 */
void is_pint(sstack_t **head, unsigned int number)
{
	number = number;
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * is_pop- function that removes the top of the stack
 * @head: top of the stack
 * @number: integer
 */
void is_pop(sstack_t **head, unsigned int number)
{
	sstack_t *aux;

	number = number;
	if (*head == NULL || head == NULL)
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't pop an empty stack\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		aux = (*head)->next;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
		free(*head), *head = NULL;
}
/**
 * is_swap- function that swaps the top two elements
 * @head: pointer to top
 * @number: integer
 */
void is_swap(sstack_t **head, unsigned int number)
{
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n;
		(*head)->next->n = (*head)->n;
		(*head)->n = x;
	}
	else
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't swap, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
