#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_number - Prints a number of any digit.
 *
 * @n: The number to be printed.
 * @base: The base of the number system to be printed.
 * @uppercase: A flag indicating whether to use uppercase letters for the digits
 *              (for bases greater than 10).
 * @print: The function to use for printing individual characters.
 *
 * Return: The number of characters printed.
 */
static int print_number(unsigned long int n, unsigned int base,
                         int uppercase, int (*print)(char))
{
  char digits[] = "0123456789abcdef";
  char buffer[50];
  char *pos = &buffer[49];
  int count = 0;

  if (n == 0)
    return (print('0'));

  if (base < 2 || base > 16)
    return (0);

  *pos = '\0';

  while (n != 0)
  {
    *--pos = digits[n % base];
    n /= base;
  }

  if (uppercase)
    for (; *pos != '\0'; pos++)
      if (*pos >= 'a' && *pos <= 'z')
        *pos = *pos - ('a' - 'A');

  for (; *pos != '\0'; pos++)
  {
    if (print(*pos) < 0)
      return (-1);

    count++;
  }

  return (count);
}

/**
 * _printf - Prints a formatted string to the standard output.
 *
 * @format: The format string to print.
 * @...: The optional arguments to be inserted into the format string.
 *
 * Return: The number of characters printed (excluding the null byte used to end
 *         output to strings), or a negative value if an error occurs.
 */
int _printf(const char *format, ...)
{
  va_list args;
  int count = 0;

  va_start(args, format);

  while (*format != '\0')
  {
    if (*format != '%')
    {
      if (putchar(*format) < 0)
      {
        va_end(args);
        return (-1);
      }

      count++;
    }
    else
    {
      int width = 0;
      int precision = -1;
      int length = 0;
      int uppercase = 0;
      int prefix = 0;
      int sign = 0;
      char pad = ' ';

      format++;

      while (*format != '\0' && (*format == '-' || *format == '+' ||
                                 *format == ' ' || *format == '#' ||
                                 *format == '0'))
      {
        if (*format == '-')
          pad = '-';
        else if (*format == '+')
          sign = '+';
        else if (*format == ' ')
          sign = ' ';
        else if (*format == '#')
          prefix = 1;
        else if (*format == '0' && width == 0 && precision == -1)
          pad = '0';

        format++;
      }

      while (*format != '\0' && (*format >= '0' && *format <= '9'))
      {
        width = width * 10 + (*format - '0');
        format++;
      }

      if (*format == '.')
      {
        format++;

        precision = 0;

        while (*format != '\0' && (*format >= '0' && *format <= '9'))
        {
          precision = precision * 10 + (*format - '0');
    format++;
}
