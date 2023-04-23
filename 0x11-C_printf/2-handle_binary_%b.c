#include "main.h"

/**
 * handle_binary - Converts an unsigned integer to binary and prints it
 * @args: A va_list of arguments passed to the calling function
 * Return: The total number of characters printed,
 * including the converted number
 */
int handle_binary(va_list args)
{
	char buffer[33];
	unsigned int num;
	int i;

	num = va_arg(args, unsigned int);
	i = 0;
	while (num)
	{
		buffer[i++] = (num % 2) + '0';
		num >>= 1;
	}
	while (i--)
		write(1, &buffer[i], 1);
	return (i);
}
