#include "monty.h"
/**
  * pall - prints all arguments inserted.
  * @stack: double pointer to stack;
  * @line_number: number of lines.
  *
  * Return: void
  */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == *stack)
		{
			return;
		}
	}
}

/**
  * pint - prints the value at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack != NULL)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
  * pchar - prints the char at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	int num;

	if (var.stack_len < 1)
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pchar, stack empty\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	num = (*stack)->n;
	if (!isascii(num))
	{
		dprintf(STDOUT_FILENO,
			"L%u: can't pchar, value out of range\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", num);
}

/**
  * pstr - prints the string starting at the top of the stack.
  * @stack: double pointer to stack.
  * @line_number: number of lines.
  *
  * Return: void.
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *stack;

	while (temp && temp->n > 0 && temp->n < 128)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	
	printf("\n");
}
