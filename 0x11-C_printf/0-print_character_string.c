#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * handle_binary - Converts an unsigned integer to binary and prints it
 * @args: A va_list of arguments passed to the calling function
 *
 * Return: The total number of characters printed,
 * including the converted number
 */
int handle_binary(va_list args);
/**
 * _printf - produces output according to a format
 * @format: character string containing format specifier
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int i = 0, printed_chars = 0, len = 0;
	va_list args;

	va_start(args, format);
	for (; (*format); format++)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed_chars++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = 'h';

						if(c)
						       c = va_arg(args, int);
						printed_chars++;
						break;
					}
				case 's':
				{
					char *s = va_arg(args, char*);

					for (; s[len]; i++)
					{
						len++;
					}
					write(1, s, len);
					printed_chars += len;
					break;
				}
				case '%':
					{
						write(1, "%", 1);
						printed_chars++;
						break;
					}
				case 'b':
					{
						printed_chars = handle_binary(args);
						break;
					}
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
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
