#ifndef __MONTY__
#define __MONTY__

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} dlistint_t, stack_t;

extern dlistint_t *stack;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/*FUNCTIONS*/

void push(dlistint_t **stack, unsigned int num);
size_t print_dlistint(const dlistint_t *h);
size_t dlistint_len(const dlistint_t *h);
dlistint_t *add_dnodeint(dlistint_t **head, const int n);
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n);
void join_tail(dlistint_t *h, dlistint_t *new);
void free_dlistint(dlistint_t *head);
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);
void match_parameter(char *s, unsigned int val, unsigned int linenum);
void read_textfile(char *filename);
void read_file(FILE *fd);
void get_cmd(char *lineptr, unsigned int linenum);
void pall(dlistint_t **stack, __attribute__((unused)) unsigned int num);
void pint(dlistint_t **stack, __attribute__((unused))unsigned int num);
void err(int error_code, ...);
void err2(int error_code, ...);
void string_err(int error_code, ...);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap_nodes(stack_t **stack, unsigned int line_number);
void add_nodes(stack_t **stack, unsigned int line_number);
void sub_nodes(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul_nodes(stack_t **stack, unsigned int line_number);
void mod_nodes(stack_t **stack, unsigned int line_number);
#endif
