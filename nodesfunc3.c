#include "monty.h"

/**
 * mul_nodes - Multiplication of the top two elements of the stack.
 * @stack: Pointer to the stack.
 * @line_number: Interger representing the line number of execution
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to the stack
 * @line_number: Interger representing the line number of execution
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err2(8, line_number, "mod");

	if ((*stack)->n == 0)
		err2(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
