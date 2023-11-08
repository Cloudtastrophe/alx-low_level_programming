#include "function_pointers.h"
#include <stdio.h>

/**
 * print_name - Prints a name using a pointer to function.
 * @name: String to print.
 * @f: Pointer to the function to use for printing.
 *
 * Return: Nothing.
 **/
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
