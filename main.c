#include "library.h"
/**
* main- Entry point
* @argc: argc
* @argv: argv
* Return: always 0
*/
int main(int argc, char *argv[])
{
	sstack_t *head;
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
		{"rotr", is_rotr},
		{"stack", is_stack},
		{"queue", is_queue}
	};

	head = NULL;
	if (argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	read_filex(argv[1], opd, &head);
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
	int fd, reader = 1024, i = 0, j = 0, closer = 0;
	char buffer[1024], *line;

	numbers[0] = 0;
	line = malloc(1024);
	if (line == NULL)
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	fd = open(file, O_RDONLY, 0600);
	if (fd == -1)
		fprintf(stderr, "Error: Can't open file %s\n", file), exit(EXIT_FAILURE);
	while (reader == 1024)
	{
		reader = read(fd, buffer, 1024);
		if (reader == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file\n");
			exit(98);
		}
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				numbers[0] = numbers[0] + 1;
				search_in_opd(line, opd, head), j = 0;
				free(line);
				line = malloc(1024);
				i++;
			}
			line[j] = buffer[i], i++, j++;
		}
	}
	closer = close(fd);
	if (closer == -1)
		exit(EXIT_FAILURE);
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
	int i = 0, t = 0, j = 0;
	unsigned int x = 0;

	while (j < 18)
	{
		i = 0, t = 0;
		while (line[i] != ' ' && line[i])
		{
			if (line[i] == opd[j].opcode[i])
				t++;
			i++;
		}
		if (opd[j].opcode[i] != '\0')
			t = 0;
		if (i == t)
		{
			if (j == 0)
				x = get_int(line);
			opd[j].f(head, x);
			break;
		}
		j++;
	}
	if (i != t)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", numbers[0], line);
		exit(EXIT_FAILURE);
	}
}
