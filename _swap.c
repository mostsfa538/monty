#include "monty.h"

/**
 * _swap - swap last two digits
 * @stack: the stack
 * @data: data
 *
 * Return: void
 */
void _swap(stack_t **stack, unsigned int data)
{
	int last = 0;

	if (!(*stack) || !(*stack)->prev)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", data);
		clean_exit();
	}

	last = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = last;
}
