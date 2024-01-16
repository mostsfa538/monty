#include "monty.h"

/**
 * _pop - pop the last element
 * @stack: the stack
 * @data: data
 *
 * Return: void
 */

void _pop(stack_t **stack, unsigned int data)
{
	stack_t *p = *stack;
	
	if (state.stack_size == 0)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", data);
		clean_exit();
	}
	
	*stack = (*stack)->prev;
	if (*stack)
		(*stack)->next = NULL;

	free(p);
	state.stack_size--;
}
