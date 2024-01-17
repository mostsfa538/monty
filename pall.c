#include "monty.h"

/**
 * _pall - prints all the values on the stack
 * @stack: the stack
 * @data: data
 *
 * Return: void
 */
void _pall(stack_t **stack, unsigned int data)
{
	stack_t *p = *stack;
	(void)data;

	if (stack == NULL || *stack == NULL)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->prev;
	}
}
