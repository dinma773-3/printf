#include "main.h"

/**
 * print_unsigned - Prints an unsigned int number
 * @types: A va_list containing the unsigned int to be printed
 * @buffer: The buffer in which to print the output
 * @flags: The active flags
 * @width: The minimum width of the output
 * @precision: The precision of the output
 * @size: The size of the buffer
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list types, char buffer[],
                   int flags, int width, int precision, int size)
{
	unsigned int num;
	int count = 0;
	char *str_num;
	char pad_char = ' ';
	int pad_count = 0;

	num = va_arg(types, unsigned int);
	str_num = convert_unsigned(num, 10);

	if (str_num == NULL)
		return (-1);

	if (flags & F_ZERO)
		pad_char = '0';

	if (precision == 0 && num == 0)
		str_num[0] = '\0';

	if (precision > 0 && precision > (int)strlen(str_num))
	{
		pad_count = precision - strlen(str_num);
	}

	if (width > (int)strlen(str_num) + pad_count)
	{
		pad_count += width - (int)strlen(str_num) - pad_count;
	}

	if (!(flags & F_MINUS))
		count += pad(pad_char, pad_count, buffer, size);

	count += _puts(str_num, buffer, size);

	if (flags & F_MINUS)
		count += pad(pad_char, pad_count, buffer, size);

	free(str_num);

	return (count);
}
