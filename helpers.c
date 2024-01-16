#include "monty.h"

/**
 * stack_free - free stack
 * @stack: Pointer to stack
 */
void stack_free(stack_t *stack)
{
	stack_t *h = stack;
	stack_t *temp = NULL;

	while (h)
	{
		temp = h->prev;
		free(h);
		h = temp;
	}
}

/**
 * clean_exit - free the memory and exit with EXIT_FAILURE
 */
void clean_exit(void)
{
	state.buff_line != NULL ? free(state.buff_line) : (void)0;
	state.stack != NULL ? stack_free(state.stack) : (void)0;
	exit(EXIT_FAILURE);
}

/**
 * isnumber - checks if number or not
 * @str: Pointer to string
 *
 * Return: 1 if number else 0
 */
int isnumber(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;

	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}

	return (1);
}


/**
 * str_to_num - convert string to number
 * @str: Pointer to string
 *
 * Return: converted number
 */
int str_to_num(char *str)
{
	int result = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		str++;
		sign *= -1;
	}

	result = atoi(str) * sign;

	return (result);
}
