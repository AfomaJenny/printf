#include "main.h"
/**
* get_precision - calculate the precision for printing
* @format: formatted string in which to print the arguments
* @i: pointer to current index
* @list: variable argument list
*
* Return: precision
*/
int get_precision(const char *format, int *i, va_list list)
{
	int current_index = *i + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}

	*i = current_index - 1;
	return (precision);
}
