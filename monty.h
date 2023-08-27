#ifndef _MONTY_H_
#define _MONTY_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>


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
} stack_t;

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
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - structures at global scope
 * @lifo: is either stack or queue
 * @line: the present line
 * @arg: the second parameter inside the current line
 * @head: the doubly linked list
 * @fd: the file descriptor
 * @buffer: container for input text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
	int lifo;
	unsigned int line;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t glovar;
/* opcode instructuions*/

void _pint(stack_t **doubly, unsigned int cline);
void _pop(stack_t **doubly, unsigned int cline);
void _push(stack_t **stack, unsigned int line_number);
void _swap(stack_t **doubly, unsigned int cline);
void _queue(stack_t **doubly, unsigned int cline);
void _stack(stack_t **doubly, unsigned int cline);
void _add(stack_t **doubly, unsigned int cline);
void _nop(stack_t **doubly, unsigned int cline);
void _sub(stack_t **doubly, unsigned int cline);
void _pall(stack_t **stack, unsigned int line_number);
void _div(stack_t **doubly, unsigned int cline);
void _mul(stack_t **doubly, unsigned int cline);
void _mod(stack_t **doubly, unsigned int cline);
void _pchar(stack_t **doubly, unsigned int cline);
void _pstr(stack_t **doubly, unsigned int cline);
void _rotl(stack_t **doubly, unsigned int cline);
void _rotr(stack_t **doubly, unsigned int cline);

/*get function*/
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number);

/*custom functions*/
void *_realloc(void *pointer, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);


/* doubly linked list functions */
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void free_dlistint(stack_t *head);

/* main */
void free_glovar(void);
void start_glovar(FILE *fd);
FILE *verify_input(int argc, char *argv[]);
#endif