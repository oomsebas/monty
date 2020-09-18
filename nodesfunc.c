#include "monty.h"

/**
 *push - function that adds a node to the stack
 *@stack: pointer to the stack
 *@num: number to add to the stack
 *return: None
 */
void  push(dlistint_t **stack, unsigned int num)
{

	add_dnodeint(stack, num);
}

/**
 * pall - print the elements of a stack
 *@stack: the stack to print
 *@num: unused attribute
 *returns: None
 */
void pall(dlistint_t **stack, __attribute__((unused))unsigned int num)
{
	print_dlistint(*stack);
}
/**
 *pint - print the last push element of the stack
 *@stack: the stack to be printed
 *@num: unused
 *Return: None
 */
void pint(dlistint_t **stack, unsigned int num)
{
	if (stack == NULL || *stack == NULL)
		err2(6, num);
	printf("%d\n", (*stack)->n);
}

/**
 * pop_top - removes  a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		err2(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
