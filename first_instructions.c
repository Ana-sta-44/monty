#include "monty.h"

/**
 * free_glovar - frees the global variables
 *
 * Return: no value returned
 */
void free_glovar(void)
{
	free_dlistint(glovar.head);
	free(glovar.buffer);
	fclose(glovar.fd);
}

/**
 * start_glovar - initializes the global variables
 *
 * @fd: the file descriptor
 * Return: no value returned
 */

void start_glovar(FILE *fd)
{
	glovar.lifo = 1;
	glovar.line = 1;
	glovar.arg = NULL;
	glovar.head = NULL;
	glovar.fd = fd;
	glovar.buffer = NULL;
}


/**
 * get_opcodes - selects the correct opcode to perform
 *
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruction[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"queue", _queue},
		{"stack", _stack},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruction[i].opcode; i++)
	{
		if (strcmp(instruction[i].opcode, opc) == 0)
			break;
	}

	return (instruction[i].f);
}


/**
 * verify_input - function to checks if file exists and if
 * the file can be opened
 *
 * @argc: the argument count
 * @argv: the argument vector
 * Return: the file struct
 */

FILE *verify_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}
