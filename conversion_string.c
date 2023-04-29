#include "main.h"

/**
 * int_to_buffer - converts integer to buffer
 * @n: integer to convert
 * @buffer: buffer to store result
 * @buffer_size: size of buffer
 *
 * Return: length of buffer
 */
int int_to_buffer(int n, char *buffer, int buffer_size)
{
	int i = 0;
	int sign = n < 0;

	if (sign)
		n = -n;
	while (n && i < buffer_size - 1)
	{
		buffer[i++] = n % 10 + '0';
		n /= 10;
	}
	if (sign && i < buffer_size - 1)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (i);
}
/**
 * handle_reversed_string - handles reversed string conversion specifier
 * @args: argument list
 * @printed_chars: number of characters printed
 *
 * Return: updated number of printed characters
 */
int handle_reversed_string(va_list args, int printed_chars)
{
	char *str = va_arg(args, char *);
	int len = 0;
	int i = 0;

	while (str[len] != '\0')
		len++;
	if (str == NULL)
		str = "(null)";
	for (i = len; i >= 0; i--)
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
 * print_padding - Prints padding character 'width' number of times.
 * @width: The number of times to print the padding character.
 * @printed_chars: The running total of printed characters.
 * @padding_char: The padding character to print.
 *
 * Return: The updated count of printed characters.
 */
int print_padding(int width, int printed_chars, char padding_char)
{
	while (width--)
	{
		write(1, &padding_char, 1);
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * handle_unknown_specifier - Handles unknown conversion specifiers by
 *                             printing the specifier itself.
 * @format: The format string containing the specifier.
 * @printed_chars: The running total of printed characters.
 *
 * Return: The updated count of printed characters.
 */
int handle_unknown_specifier(const char *format, int printed_chars)
{
	write(1, "%", 1);
	write(1, &format[0], 1);
	format++;
	printed_chars += 2;
	return (printed_chars);
}
/**
 * handle_rot13_string - Encodes a string in ROT13 and prints the result.
 * @args: A va_list of arguments containing the string to encode.
 * @printed_chars: The running total of printed characters.
 *
 * Return: The updated count of printed characters.
 */
int handle_rot13_string(va_list args, int printed_chars)
{
	char *str = va_arg(args, char*);
	char c;

	while (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			c = ((*str - 'a') + 13) % 26 + 'a';
		else if (*str >= 'A' && *str <= 'Z')
			c = ((*str - 'A') + 13) % 26 + 'A';
		else
			c = *str;
		write(1, &c, 1);
		printed_chars++;
		str++;
	}
	return (printed_chars);
}
