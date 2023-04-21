#include "main.h"
/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 *
 * Return: number of all character in the arguments
 */
int _print(const char *format, ...)
{
	int count = 0, len = 0;

	va_list args;
	va_start(args, format);
	for (;(*format); format++){
		if (*format != '%')
		{
			write(1, format, 1);
			count++;
		}
		else
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);
						_putchar(c);
						count++;
						break;
					}
				case 's':
					{
						char *s = va_arg(args, char*);
						int i = 0;
						for (; s[i]; i++)
							len++;
						i = 0;
						while (i < len)
						{
							_putchar(s);
							i++;
						}
						count += len;
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						count++;
						break;
					}
			}
		}
	}
	va_end(args);
	return (count);
}

