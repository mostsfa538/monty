#include "monty.h"

/**
 * _print - prints the value at the top of the stack
 * @stack: Pointer to the pointer to the head of the stack
 * @data: Line number (unused in this function)
 *
 * Return: void
 */
void _print(stack_t **stack, unsigned int data)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", data);
		clean_exit();
	}

	printf("%d\n", (*stack)->n);
}
