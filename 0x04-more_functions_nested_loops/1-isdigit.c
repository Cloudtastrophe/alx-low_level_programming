#include "main.h"
/**
 * _isdigit - function checks for a digit (0 through 9)
 * @c: int to be checked
 * Return: 1 if c is a digit and 0 if not 
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')

	{
		return 1;
	}
	
	else 
	
	{
		return 0;
	}
}
