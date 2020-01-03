#include "library.h"
/**
* get_int- this function get the integer in the line
* @buffer: path of the file to read
*
* Return: The number Always 0 (Success)
*/
int get_int(char *buffer)
{
	int i = 0, j = 0, t = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ')
		{
			while (buffer[i] == ' ')
				i++;
			j = i;
			if ((buffer[i] < 48 || buffer[i] > 57) && buffer[i] != 45)
			{
				fprintf(stderr, "L%d: usage: push integer\n", numbers[0]);
				exit(EXIT_FAILURE);
			}
			if (buffer[i] == '-')
				i++;
			while (buffer[i] != ' ' && buffer[i])
			{
				if (buffer[i] >= 48 && buffer[i] <= 57)
					i = i;
				else
					t++;
				i++;
			}
			if (t == 0)
			{
				buffer = buffer + j;
				i = atoi(buffer);
				return (i);
			}
			if (t != 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", numbers[0]);
				exit(EXIT_FAILURE);
			}
		}
		t = 0, i++;
	}
	fprintf(stderr, "L%d: usage: push integer\n", numbers[0]);
	exit(EXIT_FAILURE);
}
