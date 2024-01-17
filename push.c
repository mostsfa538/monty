#include "monty.h"

/**
 * _push - pushs in stack
 * @stack: the stack
 * @data: data
 *
 * Return: void
 */
void _push(stack_t **stack, unsigned int data)
{
	stack_t *newNode = NULL;
	char *opcode_arg = strtok(NULL, " ");
	size_t last_arg = 0;

	if (opcode_arg != NULL)
	{
		last_arg = strlen(opcode_arg) - 1;
		(opcode_arg[last_arg] == '\n') ? (opcode_arg[last_arg] = '\0') : 0;
	}

	if (opcode_arg == NULL || !isnumber(opcode_arg) || opcode_arg[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", data);
		clean_exit();
	}

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clean_exit();
	}

	if (state.stack_size == 0)
	{
		newNode->prev = NULL;
		newNode->next = NULL;
	}

	else
	{
		newNode->prev = *stack;
		(*stack)->next = newNode;
	}

	newNode->n = str_to_num(opcode_arg);
	*stack = newNode;

	state.stack_size++;
}
