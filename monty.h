#ifndef MAIN
#define MAIN
#define _GNU_SOURCE

/******HEADERS******/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
/******HEADERS-END******/

/******STRUCTURES******/
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
 * struct data_s - Needed data.
 *
 * @value: value.
 * @file: monty file fd.
 * @line: line content.
 * @mode: Data insertion mode.
 *
 * Description: Needed data.
 */
typedef struct data_s
{
	char *value;
	FILE *file;
	char *line;
	int mode;
}  data_t;

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
/******STRUCTURES-END******/

/******GLOBAL_VARIABLE******/
extern data_t data;
/******GLOBAL_VARIABLE-END******/

/******MAIN-FUNCTIONS******/
int execute(stack_t **head, unsigned int line_number);
void free_stack(stack_t *head);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
/******MAIN-FUNCTIONS-END******/

/******OP-FUNCTIONS******/
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_swap(stack_t **head, unsigned int line_number);
void op_add(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_pchar(stack_t **head, unsigned int line_number);
void op_pstr(stack_t **head, unsigned int line_number);
void op_rotl(stack_t **head, unsigned int line_number);
void op_rotr(stack_t **head, unsigned int line_number);
void op_queue(stack_t **head, unsigned int line_number);
void op_stack(stack_t **head, unsigned int line_number);
/******OP-FUNCTIONS-END******/
#endif
