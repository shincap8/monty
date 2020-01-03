#include "library.h"
/**
 * is_mod - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_mod(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	int x = 0;

	number = number;
	if ((*head)->next != NULL)
	{
		x = (*head)->next->n % (*head)->n;
		aux = (*head)->next;
		aux->n = x;
		free(*head);
		aux->prev = NULL;
		*head = aux;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
}
/**
 * is_mul - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_pchar(sstack_t **head, unsigned int number)
{
	char ascii;

	number = number;
	if ((*head)->n < 0 || (*head)->n > 255)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", numbers[0]);
		exit(EXIT_FAILURE);
	}
	ascii = (*head)->n;
	printf("%c\n", ascii);
}
/**
 * is_pstr - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_pstr(sstack_t **head, unsigned int number)
{
	sstack_t *aux;
	char print;
	int t = 0;

	number = number;
	if (head == NULL || *head == NULL)
		printf("\n");
	aux = *head;
	while(aux)
	{
		if (aux->n == 0 || aux->n < 0 || aux->n > 255)
			break;
		print = aux->n;
		printf("%c", print);
		aux = aux->next;
		t = 1;
	}
	if (t == 1)
		printf("\n");
}
/**
 * is_rotl - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_rotl(sstack_t **head, unsigned int number)
{
	sstack_t *aux = *head, *tmp = *head;

	number = number;
	while (aux)
	{
		if (aux->next == NULL)
		{
			(*head) = (*head)->next;
			(*head)->prev = NULL;
			aux->next = tmp;
			tmp->next = NULL;
			break;
		}
		aux = aux->next;
	}
}
/**
 * is_rotr - adds the top two elements of the stack
 * @head: pointer to top
 * @number: integer
 */
void is_rotr(sstack_t **head, unsigned int number)
{
	sstack_t *aux = *head;

	number = number;
	while (aux)
	{
		if (aux->next == NULL)
		{
			aux->prev->next = NULL;
			(*head)->prev = aux;
			aux->next = *head;
			aux->prev = NULL;
			*(head) = aux;
			break;
		}
		aux = aux->next;
	}
}
