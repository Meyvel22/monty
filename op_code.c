#include "monty.h"
/**
  * get_opcode - checks whether the opcode exists.
  * @token: opcode passed.
  *
  * Return: pointer to function for opcode or NULL.
  */
void (*get_opcode(char *token))(stack_t **head, unsigned int line_number)
{
	size_t i;
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
		{NULL, NULL}
	};
	
	for (i = 0; opc[i].opcode != NULL; i++)
	{
		if (strcmp(opc[i].opcode, token) == 0)
		{
			opc[i].f(head, line_number);
			return;
		}
	}

	dprintf(STDOUT_FILENO,
		"L%u: unknown instruction %s\n",
		line_number, token);
	exit(EXIT_FAILURE);
}
