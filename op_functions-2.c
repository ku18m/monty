#include "monty.h"

/**
 * op_pall - prints the stack.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_pall(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;
	(void)data;

	h = *head;
	if (h == NULL)
		return;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * op_pchar - prints the char at the top of the stack,
 * followed by a new line.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_pchar(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * op_pint - prints the top.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * op_pop - prints the top.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(data.file);
		free(data.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
 * op_pstr - prints the string starting at the top of the stack,
 * followed by a new.
 *
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_pstr(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	(void)line_number;
	(void)data;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
