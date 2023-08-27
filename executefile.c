#include "monty.h"

global_t glovar;

/**
 * main - start point of program execution
 *
 * @argc: the argument count
 * @argv: the argument vector
 * Return: returns 0 on success
 */

int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t siz = 256,  nlines = 0;
	char *line_no[2] = {NULL, NULL};

	fd = verify_input(argc, argv);
	start_glovar(fd);
	nlines = getline(&glovar.buffer, &siz, fd);
	while (nlines != -1)
	{
		line_no[0] = strtok(glovar.buffer, " \t\n");
		if (line_no[0] && line_no[0][0] != '#')
		{
			f = get_opcodes(line_no[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glovar.line);
				dprintf(2, "unknown instruction %s\n", line_no[0]);
				free_glovar();
				exit(EXIT_FAILURE);
			}
			glovar.arg = strtok(NULL, " \t\n");
			f(&glovar.head, glovar.line);
		}
		nlines = getline(&glovar.buffer, &siz, fd);
		glovar.line++;
	}
	free_glovar();
	return (0);
}
