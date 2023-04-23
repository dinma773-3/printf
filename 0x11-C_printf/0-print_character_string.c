#include "main.h"

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
				case 'd':
				case 'i':
					{
						handle_integer(args, printed_chars);
						break;
					}
				case '\0':
					{
						va_end(args);
						return (-1);
					}
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
