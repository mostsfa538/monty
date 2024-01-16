#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct state_t - struct to store as a global struct
 * @data: data
 * @buff_size: buffer size
 * buff_line: Pointer to buffer line
 * @stack: Pointer to stack
 * stack_size: size of stack
 */
typedef struct state_s
{
	unsigned int data;
	size_t buff_size;
	char *buff_line;
	stack_t *stack;
	size_t stack_size;
} state_t;
/*	 global vairable 	*/
extern state_t state

/*	 function readd and exectute instruction_t	*/
void read_instructions(FILE *file);
void execute_instruction(instruction_t *stack_handle);

/*	 functions of stack	 */

void _push(stack_t **stack, unsigned int date);
void _pop(stack_t **stack, unsigned int data);
void _pall(stack_t **stack, unsigned int data);
void _pint(stack_t **stack, unsigned int data);
void _swap(stack_t **stack, unsigned int data);
void _nop(stack_t **stack, unsigned int data);
void _add(stack_t **stack, unsigned int data);
void _sub(stack_t **stack, unsigned int data);
void _div(stack_t **stack, unsigned int data);
void _mul(stack_t **stack, unsigned int data);
void _mod(stack_t **stack, unsigned int data);

/* 	helper functions	 */
void stack_free(stack_t *stack);
void clean_exit(void);
int isnumber(char *str);
int str_to_num(char *str);

#endif /* MONTY_H */
