#include "main.h"
/**
 * handle_integer - handles integer conversion specifier
 * @args: arguments passed to printf
 * @op: a struct thst contains optional parameter specifiers
 * @printed_chars: total number of characters printed so far
 *
 * Return: total number of characters printed (including new ones)
 */
int handle_integer(va_list args, int printed_chars, t_options op)
{
	int num = va_arg(args, int);
	char buffer[BUFFER];
	int precision;
	int len = 0;

	if (op.Long)
		num = (long int)num;
	if (op.Short)
		num = (short int)num;
	int_to_buffer(num, buffer, BUFFER);
	while (buffer[len] != '\0')
		len++;

	precision = op.precision < 0 ? 0 : op.precision;

	if (op.precision_set && precision > len)
	{
		precision -= len;
		while (precision--)
		{
			write(1, "0", 1);
			printed_chars++;
		}
	}

	printed_chars = print_integer(buffer, op, len, printed_chars);

	return (printed_chars);
}
/**
 * print_integer - handles integer conversion specifier
 * @buffer: arguments passed to printf
 * @printed_chars: total number of characters printed so far
 * @len: int variable contains length of buffer
 * @op: A struct contains the optional parameter specifiers
 *
 * Return: total number of characters printed (including new ones)
 */
int print_integer(char *buffer, t_options op, int len, int printed_chars)
{
	int field_width;
	char pad_char;
	int num_padding_chars;

	field_width = op.width < 0 ? -op.width : op.width;
	if (field_width > len)
	{
		pad_char = op.zero ? '0' : ' ';
		num_padding_chars = field_width - len;

		if (op.minus)
		{
			printed_chars += print_number(buffer, op);
			while (num_padding_chars--)
			{
				write(1, &pad_char, 1);
				printed_chars++;
			}
		}
		else
		{
			while (num_padding_chars--)
			{
				write(1, &pad_char, 1);
				printed_chars++;
			}
			printed_chars += print_number(buffer, op);
		}
	}
	else
		printed_chars += print_number(buffer, op);
	return (printed_chars);
}
/**
 * handle_binary - Converts an unsigned integer to binary and prints it
 * @args: A va_list of arguments passed to the calling function
 * @op: A struct contains the optional parameter specifiers
 * @printed_chars: The total number of characters printed so far
 *
 * Return: The total number of characters printed,
 * including the converted number
 */
int handle_binary(va_list args, int printed_chars, t_options op)
{
	char buffer[BUFFER];
	unsigned int num = va_arg(args, unsigned int);
	int i = 0;
	int precision;

	while (num)
	{
		buffer[i++] = (num % 2) + '0';
		num >>= 1;
	}
	precision = op.precision < 0 ? 0 : op.precision;
	if (op.precision_set && precision > i)
	{
		precision -= i;
		while (precision--)
		{
			write(1, "0", 1);
			printed_chars++;
		}
	}
	while (i--)
		write(1, &buffer[i], 1);
	return (printed_chars);
}
/**
 * h_unsigned_int - handles the 'u' specifier
 *
 * @args: arguments list containing the unsigned int to be printed
 * @printed_chars: the running count of printed characters
 * @op: A struct contains the optional parameter specifiers
 *
 * Return: the number of characters printed
 */
int h_unsigned_int(va_list args, int printed_chars, t_options op)
{
	char buffer[BUFFER];
	unsigned int num = va_arg(args, unsigned int);
	int precision;
	int i = 0, base = 10;

	if (op.Long)
		num = (long int)num;
	if (op.Short)
		num = (short int)num;
	while (num)
	{
		buffer[i++] = "0123456789abcdef"[num % base];
		num /= base;
	}

	precision = op.precision < 0 ? 0 : op.precision;
	if (op.precision_set && precision > i)
	{
		precision -= i;
		while (precision--)
		{
			write(1, "0", 1);
			printed_chars++;
		}
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
/**
 * handle_octal - handles the 'o' specifier
 *
 * @args: arguments list containing the unsigned int to be printed
 * @printed_chars: the running count of printed characters
 * @op: A struct contains the optional parameter specifiers
 *
 * Return: the number of characters printed
 */
int handle_octal(va_list args, int printed_chars, t_options op)
{
	char buffer[BUFFER] = {0};
	unsigned int num = va_arg(args, unsigned int);
	int i = 0, precision;

	while (num)
	{
		buffer[i++] = (num % 8) + '0';
		num /= 8;
	}
	precision = op.precision < 0 ? 0 : op.precision;
	if (op.precision_set && precision > i)
	{
		precision -= i;
		while (precision--)
		{
			write(1, "0", 1);
			printed_chars++;
		}
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
