#include "monty.h"

/**
 * _mul - multiplies last two element in stack
 * @stack: the stack
 * @data: data.
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int data)
{
	int sum = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", data);
		clean_exit();
	}

	sum = (*stack)->n * (*stack)->prev->n;
	_pop(&(*stack), data);
	(*stack)->n = sum;
}
