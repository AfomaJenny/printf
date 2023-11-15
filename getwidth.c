#include "main.h"
/**
* get_width - calculates the width for printing
* @format: formatted string in which arguments are printed
* @i: pointer to the current indes
* @list: variable argument list
*
* Return: width
*/
int get_width(const char *format, int *i, va_list list)
{
	int current_index;
	int width = 0;

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = current_index - 1;
	return (width);
}
