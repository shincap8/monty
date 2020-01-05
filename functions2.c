#include "monty.h"
/**
 * is_add- adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_add(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n + (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't add, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_nop- function that doesn't do anything
 * @head: pointer to top
 * @number: integer
 */
void is_nop(sstack_t **head, unsigned int number)
{
	head = head;
	number = number;
}
/**
 * is_sub - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_sub(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n - (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't sub, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_div - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_div(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->n == 0)
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: division by zero\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n / (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't div, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_mul - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_mul(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n * (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		free_dlistint(*head);
		fprintf(stderr, "L%d: can't mul, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
