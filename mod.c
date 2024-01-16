#include "monty.h"

/**
 * _add - rest of the division last two element in stack
 * @stack: the stack
 * @data: data.
 *
 * Return: void
 */
void _mod(stack_t **stack, unsigned int data)
{
	int sum = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", data);
		clean_exit();
	}

	if (state.stack->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", data);
		clean_exit();
	}

	sum = (*stack)->prev->n % (*stack)->n;
	_pop(&(*stack), data);
	(*stack)->n = sum;
}
