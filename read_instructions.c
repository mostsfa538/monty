#include "monty.h"

/**
 * read_instructions - read instructions of input
 * @file: Pointer to file that have the input
 */
void read_instructions(FILE *file)
{
	instruction_t handel_stack[] = {
		{"push", _push},
		{"pop", _pop},
		{"pall", _pall},
		{"print", _print},
		{"swap", _swap},
		{"nop", _nop},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{NULL, NULL}
	};

	while (getline(&(state.buff_line), &(state.buff_size), file) != -1)
	{
		state.data++;
		execute_instruction(stack_handle);
	}
	free(state.buff_line);
	stack_free(state.stack);

}
