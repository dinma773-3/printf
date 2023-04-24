#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - prints output according to a format.
 * @format: character string containing zero or more directives.
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
        {
            int num = va_arg(args, int);
            printf("%d", num);
            format += 2;
            count++;
        }
        else if (*format == '%')
        {
            putchar('%');
            format++;
            count++;
        }
        else
        {
            putchar(*format);
            format++;
            count++;
        }
    }
    va_end(args);
    return count;
}
