#include "monty.h"

/**
 * _sub - subs last two element in stack
 * @stack: the stack
 * @data: data.
 *
 * Return: void
 */
void _sub(stack_t **stack, unsigned int data)
{
	int sub = 0;

	if (state.stack_size < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", data);
		clean_exit();
	}

	sub = (*stack)->n - (*stack)->prev->n;
	_pop(stack, data);
	(*stack)->n = sub;
}
