#include "main.h"

/**
 * handle_low_hexa - handles the 'x' specifier
 *
 * @args: arguments list containing the unsigned int to be printed
 * @printed_chars: the running count of printed characters
 * @op: formatting options
 *
 * Return: the number of characters printed
 */
int handle_low_hexa(va_list args, int printed_chars, t_options op)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER];
	int i = 0, precision, len = 0;

	if (op.Long)
		num = (long int)num;
	if (op.Short)
		num = (short int)num;
	while (num)
	{
		int r = num % 16;

		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r - 10 + 'a';
		num /= 16;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	precision = op.precision;
	while (buffer[len] != '\0')
		len++;
	if (precision > len)
	{
		precision -= len;
		while (precision--)
			printed_chars += write(1, "0", 1);
	}
	if (op.hash)
		printed_chars += write(1, "0x", 2);
	while (i--)
	{
		write(1, &buffer[i], 1);
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * handle_upper_hexa - handles the 'X' specifier
 *
 * @args: arguments list containing the unsigned int to be printed
 * @printed_chars: the running count of printed characters
 * @op: formatting options
 *
 * Return: the number of characters printed
 */
int handle_upper_hexa(va_list args, int printed_chars, t_options op)
{
	unsigned int num = va_arg(args, unsigned int);
	char buffer[BUFFER];
	int i = 0, precision = op.precision, len = 0;

	if (op.Long)
		num = (long int)num;
	if (op.Short)
		num = (short int)num;
	while (num)
	{
		int r = num % 16;

		if (r < 10)
			buffer[i++] = r + '0';
		else
			buffer[i++] = r - 10 + 'A';
		num /= 16;
	}
	if (i == 0)
		buffer[i++] = '0';
	buffer[i] = '\0';
	while (buffer[len] != '\0')
		len++;
	if (precision > len)
	{
		precision -= len;
		while (precision--)
		{
			printed_chars += write(1, "0", 1);
			len++;
		}
	}
	if (op.hash)
		printed_chars += write(1, "0x", 2);
	while (i--)
	{
		write(1, &buffer[i], 1);
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * handle_string - prints a string
 * @args: list of arguments
 * @printed_chars: number of characters printed so far
 * Return: number of characters printed
 */
int handle_string(va_list args, int printed_chars)
{
	char *str = va_arg(args, char *);
	int i = 0;

	if (str == NULL)
		str = "(null)";
	for (; str[i] != '\0'; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			printed_chars += write(1, "\\", 1);
			printed_chars += write(1, "x", 1);
			printed_chars += print_hexa(str[i], "0123456789ABCDEF", 2);
		}
		else
			printed_chars += write(1, &str[i], 1);
	}
	return (printed_chars);
}
/**
 * print_hexa - prints a hexadecimal number with a given width
 * @n: number to print
 * @charset: character set for hexadecimal numbers
 * @width: minimum width of the printed number
 * Return: number of characters printed
 */
int print_hexa(unsigned int n, const char *charset, int width)
{
	int i, printed_chars = 0;
	char buffer[BUFFER];

	if (n == 0)
		printed_chars += write(1, "0", 1);
	else
	{
		for (i = 0; n != 0; i++)
		{
			buffer[i] = charset[n % 16];
			n /= 16;
		}
		for (; i < width; i++)
			buffer[i] = '0';
		for (i = i - 1; i >= 0; i--)
			printed_chars += write(1, &buffer[i], 1);
	}
	return (printed_chars);
}
