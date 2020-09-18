#include "monty.h"
dlistint_t *stack = NULL;

/**
 *main - main program
 *@argc: number of arguments passed fro command line
 *@argv: array with the content of the commands
 *Return: 0 on success
 */
int main(int argc, char **argv)
{
	if (argc < 2 || argc > 2)
		err(1);
	read_textfile(argv[1]);
	free_dlistint(stack);
	return (0);
}

/**
 *match_parameter - find the function according the command
 *@s: the opcode tokenized to find the function to execute
 *@val: the value to oush to the stack
 *@linenum: the line number
 */
void match_parameter(char *s, unsigned int val, unsigned int linenum)
{
	instruction_t  options[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{NULL, NULL}
	};
	void (*f)(dlistint_t **stack, unsigned int line_number);
	int i = 0;


	while (options[i].opcode != NULL)
	{
		if (strcmp(s, options[i].opcode) == 0)
		{
			f = options[i].f;
			break;
		}
		i++;
	}
	if (options[i].opcode == NULL)
		err(3, linenum, s);
	if (strcmp("push",s) == 0)
		f(&stack, val);
	else
		f(&stack, linenum);
}

/**
 *read_textfile - function that reads a text file and prints it to the
 *POSIX standard output.
 *@filename: Pointer to the file to read
 *Return: the number of characters
 */
void  read_textfile(char *filename)
{
	int file_check;
	FILE *fd;

	if (filename == NULL)
		err(2, filename);

	file_check = access(filename, R_OK);
	if (file_check == -1)
		err(2, filename);
	fd = fopen(filename, "r");
	if (fd == NULL)
	{
		err(2, filename);
	}
	read_file(fd);
	fclose(fd);

}
/**
 * read_file - open the file descriptor and reads line commands
 *@fd: path to the file to read
 *return: None
 */
void read_file(FILE *fd)
{

	int i;
	char *lineptr;
	size_t n;

	lineptr = NULL;
	n = 0;

	if (fd == NULL)
	{
		err(2, "filename");
	}
	for (i = 1; getline(&lineptr, &n, fd) != EOF; i++)
	{
		if (lineptr == NULL)
			err(4);
		get_cmd(lineptr, i);
	}
	free(lineptr);
	free_dlistint(stack);

}

/**
 * get_cmd - tokenize the line command into opcode and value
 *@lineptr: pointer to the line with the command
 *@linenum: line number of the file
 *return: none
 */
void get_cmd(char *lineptr, unsigned int linenum)
{
	char *delim;
	char *opcode = NULL;
	char *value = NULL;
	int val = 0, i;

	delim = "\n ";
	opcode = strtok(lineptr, delim);
	if (opcode == NULL)
		exit(2);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "push") == 0)
	{
		if ((value != NULL) & (value[0] == '-'))
		{
			value = value + 1;
		}
		if (value == NULL)
			err(5, linenum);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				err(5, linenum);
		}
	}
	if (value != NULL)
	{
		val = atoi(value);
	}
	match_parameter(opcode, val, linenum);
}
