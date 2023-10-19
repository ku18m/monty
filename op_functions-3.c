#include "main.h"

/**
 * op_push - add node to the stack.
 *
 * @data: struct that holds data.
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_push(data_t *data, stack_t **head, unsigned int line_number)
{
	int n, j = 0, flag = 0;

	if (data->value)
	{
		if (data->value[0] == '-')
			j++;
		for (; data->value[j] != '\0'; j++)
		{
			if (data->value[j] > 57 || data->value[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(data->file);
			free(data->line);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(data->file);
		free(data->line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(data->value);
	if (data->mode == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * op_queue - prints the top.
 *
 * @data: struct that holds data.
 * @head: stack head,
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_queue(data_t *data, stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	data->mode = 1;
}

/**
 *op_rotl- rotates the stack to the top.
 *
 * @data: struct that holds data.
 * @head: stack head.
 * @line_number: line number.
 *
 *Return: Nothing.
 */
void op_rotl(data_t *data, stack_t **head, unsigned int line_number)
{
	stack_t *temp, *tmp = *head;
	(void)data;
	(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	temp = (*head)->next;
	temp->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = temp;
}

/**
 *op_rotr- rotates the stack to the bottom.
 *
 * @data: struct that holds data.
 * @head: stack head.
 * @line_number: line number.
 *
 *Return: Nothing.
 */
void op_rotr(data_t *data, stack_t **head, unsigned int line_number)
{
	stack_t *copy;
	(void)data;
	(void)line_number;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}

/**
 * op_stack - prints the top.
 *
 * @data: struct that holds data.
 * @head: stack head.
 * @line_number: line number.
 *
 * Return: Nothing.
 */
void op_stack(data_t *data, stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	data->mode = 0;
}
