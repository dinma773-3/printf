#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
  return (write(1, &c, 1));
}

/**
 * _printf - prints output according to a format.
 * @format: character string
 *
 * Return: number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
  va_list args;
  int i = 0, count = 0;
  char *str;

  va_start(args, format);
  while (format && format[i])
    {
      if (format[i] == '%')
        {
	  i++;
	  if (format[i] == 'c')
            {
	      _putchar(va_arg(args, int));
	      count++;
            }
	  else if (format[i] == 's')
            {
	      str = va_arg(args, char *);
	      if (str == NULL)
		str = "(null)";
	      while (*str)
                {
		  _putchar(*str++);
		  count++;
                }
            }
            else if (format[i] == '%')
            {
                _putchar('%');
                count++;
            }
            else if (format[i] == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
                int printed = 0;

                while (mask > 0)
                {
                    if (num & mask)
                    {
                        _putchar('1');
                        printed++;
                    }
                    else if (printed || mask == 1)
                    {
                        _putchar('0');
                        printed++;
                    }
                    mask >>= 1;
                }
                count += printed;
            }
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }
    va_end(args);
    return (count);
}
