#include "main.h"
/**
* get_size - calculates the size to cast the argument
* @format: formatted string in which to print the arguments
* @i: pointer to the current index in the format
*
* Return: size
*/
int get_size(const char *format, int *i)
{
	int current_index = *i + 1;
	int size = 0;

	if (format[current_index] == '1')
	{
		size = S_LONG;
	}
	else if (format[current_index] == 'h')
	{
		size = S_SHORT;
	}

	if (size == 0)
	{
		*i = current_index - 1;
	}
	else
	{
		*i = current_index;
	}
	return (size);
}
