#include "monty.h"

/**
 * _pall - palls in stack
 * @stack: the stack
 * @data: data
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int data)
{
	stack_t *p = *stack;
	void(data);

	while (p)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
