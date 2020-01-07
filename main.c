#include "monty.h"
/**
* main- Entry point
* @argc: argc
* @argv: argv
* Return: always 0
*/
int main(int argc, char *argv[])
{
	sstack_t *head = NULL;
	instruction_t opd[] = {
		{"push", is_push},
		{"pall", is_pall},
		{"pint", is_pint},
		{"pop", is_pop},
		{"swap", is_swap},
		{"add", is_add},
		{"nop", is_nop},
		{"sub", is_sub},
		{"div", is_div},
		{"mul", is_mul},
		{"mod", is_mod},
		{"pchar", is_pchar},
		{"pstr", is_pstr},
		{"rotl", is_rotl},
		{"rotr", is_rotr}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_filex(argv[1], opd, &head);
	if (head != NULL)
		free_dlistint(head);
	return (0);
}
/**
* read_filex - this function read the file
* @file: path of the file to read
* @opd: op code
* @head: pointer to the top of the stack
*
* Return: Always 0 (Success)
*/
void read_filex(char *file, instruction_t *opd, sstack_t **head)
{
	int i = 0;
	char *line = NULL;
	size_t line_size = 0;
	FILE *fd;

	numbers[0] = 0;
	fd = fopen(file, "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file), exit(EXIT_FAILURE);
	}
	while (getline(&line, &line_size, fd))
	{
		i = 0;
		while (line[i] != '\n')
			i++;
		numbers[0] = numbers[0] + 1;
		line[i] = '\0';
		search_in_opd(line, opd, head);
		line = NULL;
	}
	printf("final\n");
	fclose(fd);
}
/**
* search_in_opd- this function searches in the opd
* @line: line with opd
* @opd: op code array
* @head: pointer to the top of the stack
*
* Return: Always 0 (Success)
*/
void search_in_opd(char *line, instruction_t *opd, sstack_t **head)
{
	int i = 0, t = 0, j = 0, b = 0;
	unsigned int x = 0;
	char *new = NULL;

	new = extreme(line);
	while (j < 15)
	{
		i = 0, t = 0;
		while (new[i] != ' ' && new[i] != '\0' && opd[j].opcode[i != '\0'])
		{
			if (new[i] == opd[j].opcode[i])
				t++;
			i++;
		}
		if (opd[j].opcode[i] != '\0')
			t = 0;
		b = strlen(opd[j].opcode);
		if (i > b)
			break;
		if (new[0] == '\0')
		{
			printf("acá?\n");
			free(line);
			break;
		}
		if (i == t)
		{
			if (j == 0)
				x = get_int(new);
			free(line), opd[j].f(head, x);
			break;
		}
		 j++;
	}
	if (i != t)
	{
		el_error404_not_fount(i, new, line);
	}
}
/**
* el_error404_not_fount- es una chimba
* @i: integer
* @new: ne with opd
* @line: op code array
*
* Return: Always 0 (Success)
*/
void el_error404_not_fount(int i, char *new, char *line)
{
	i = 0;
	while (new[i] != ' ' && new[i] != '\0')
		i++;
	new[i] = '\0';
	fprintf(stderr, "L%d: unknown instruction %s\n", numbers[0], new);
	free(line), exit(EXIT_FAILURE);
}
