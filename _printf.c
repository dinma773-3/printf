#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    printed_chars += putchar(va_arg(args, int));
                    break;
                case 's':
                    printed_chars += printf("%s", va_arg(args, char *));
                    break;
                case '%':
                    printed_chars += putchar('%');
                    break;
                default:
                    printed_chars += putchar('%');
                    printed_chars += putchar(*format);
                    break;
            }
        }
        else
        {
            printed_chars += putchar(*format);
        }

        format++;
    }

    va_end(args);

    return printed_chars;
}
