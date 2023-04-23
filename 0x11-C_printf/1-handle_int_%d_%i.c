#include "main.h"

/**
 * handle_integer - handles integer conversion specifier
 * @args: arguments passed to printf
 * @printed_chars: total number of characters printed so far
 *
 * Return: total number of characters printed (including new ones)
 */

int handle_integer(va_list args, int printed_chars)
{
	int num = va_arg(args, int);
	char buffer[12];
	int i = 0;

	if (num < 0)
	{
		write(1, "-", 1);
		printed_chars++;
		num = num * (-1);
	}
	while (num)
	{
		buffer[i++] = (num % 10) + '0';
		num = num / 10;
	}
	if (i == 0)
		buffer[i++] = '0';
	while (i--)
	{
		write(1, &buffer[i], 1);
		printed_chars++;
	}
	return (printed_chars);
}
