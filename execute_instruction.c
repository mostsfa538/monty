#include "monty.h"

/**
 * execute_instruction - takes line by line
 * @handle_stack: take arguments
 */
void execute_instruction(instruction_t *handle_stack)
{
	size_t opcode_len = 0, i = 0;
	char *opcode = NULL;

	opcode = strtok(state.buff_line, " ");
	if (!opcode || strcmp(opcode, "\n") == 0 || strncmp(opcode, "#", 1) == 0)
	{
		return;
	}

	opcode_len = strlen(opcode);

	(opcode[opcode_len - 1] == '\n') ? (opcode[opcode_len - 1] = '\0') : 0;

	for (i = 0; handle_stack[i].opcode != NULL; i++)
	{
		if (strcmp(handle_stack[i].opcode, opcode) == 0)
		{
			handle_stack[i].f(&(state.stack), state.data);
			return;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", state.data, opcode);
		clean_exit();
}
