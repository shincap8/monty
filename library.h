#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} sstack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(sstack_t **stack, unsigned int number);
} instruction_t;
unsigned int numbers[2];
void read_filex(char *file, instruction_t *opd, sstack_t **head);
int _strcmp(char *s1, char *s2);
void is_push(sstack_t **, unsigned int);
int get_int(char *);
void is_pall(sstack_t **, unsigned int);
void search_in_opd(char *buffercito, instruction_t *opd, sstack_t **head);
void is_pint(sstack_t **, unsigned int);
void is_pop(sstack_t **, unsigned int);
void is_swap(sstack_t **, unsigned int);
void is_add(sstack_t **, unsigned int);
void is_nop(sstack_t **, unsigned int);
void is_sub(sstack_t **head, unsigned int);
void is_div(sstack_t **head, unsigned int);
void is_mul(sstack_t **head, unsigned int);
void is_mod(sstack_t **head, unsigned int);
void is_pchar(sstack_t **head, unsigned int);
void is_pstr(sstack_t **head, unsigned int);
void is_rotl(sstack_t **head, unsigned int);
void is_rotr(sstack_t **head, unsigned int);
void is_stack(sstack_t **head, unsigned int number);
void is_queue(sstack_t **head, unsigned int number);
#endif
