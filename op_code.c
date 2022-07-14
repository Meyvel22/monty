#include "monty.h"
/**
  * get_opcode - checks whether the opcode exists.
  * @token: opcode passed.
  *
  * Return: pointer to function for opcode or NULL.
  */
void (*get_opcode(char *token))(stack_t **head, unsigned int line_number)
{
	instruction_t opc[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", m_stack},
		{"queue", m_queue},
		{NULL, NULL}
	};
	
	for (i = 0; valid_opc[i].opcode != NULL; i++)
	{
		if (strcmp(valid_opc[i].opcode, op) == 0)
		{
			valid_opc[i].f(stack, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, op);
	exit(EXIT_FAILURE);
}
