#include "main.h"
/**
 * _printf - prints formatted output to stdout
 * @format: a string containing format specifiers
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	t_options options = FLAG_INIT;
	int printed_chars = 0;
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
			format = Parse_f(args, format);
			printed_chars = handle_format(args, format, options, printed_chars);
			if (*format == '\0')
			{
				va_end(args);
				return (-1);
			}
		}
	}
	va_end(args);
	return (printed_chars);
}
/**
 * handle_format - handles conversion specifier format and prints output
 *
 * @args: list of arguments passed to _printf
 * @format: format specifier string
 * @options: struct containing optional parameters for format specifier
 * @printed_chars: current count of printed characters
 *
 * Return: total count of printed characters
 */

int handle_format(va_list args, const char *format,
		t_options options, int printed_chars)
{
	if (*format == 'c')
	{
		char c = va_arg(args, int);

		write(1, &c, 1);
		printed_chars++;
	}
	else if (*format == 's')
	{
		char *s = va_arg(args, char*);
		int len = 0;

		for (; s[len]; len++)
			;
		write(1, s, len);
		printed_chars += len;
	}
	else if (*format == '%')
	{
		write(1, "%", 1);
		printed_chars++;
	}
	else if (*format == 'b')
		printed_chars += handle_binary(args, printed_chars, options);
	else if (*format == 'd' || *format == 'i')
		printed_chars += handle_integer(args, printed_chars, options);
	else if (*format == 'u')
		printed_chars = h_unsigned_int(args, printed_chars, options);
	else if (*format == 'o')
		printed_chars = handle_octal(args, printed_chars, options);
	else if (*format == 'x')
		printed_chars = handle_low_hexa(args, printed_chars, options);
	else if (*format == 'X')
		printed_chars = handle_upper_hexa(args, printed_chars, options);
	printed_chars = hand_help(format, printed_chars, args);
	return (printed_chars);
}

/**
 * hand_help - helper function that handles the printing of all non-specifier
 *             characters in a given format string.
 * @format: the format string to print.
 * @printed_chars: the total number of characters printed so far.
 * @args: a va_list of argument containing a string
 *
 * Return: the updated total number of characters printed.
 */
int hand_help(const char *format, int printed_chars, va_list args)
{
	if (*format == 'S')
		printed_chars = handle_string(args, printed_chars);
	else if (*format == 'p')
		printed_chars = handle_specifier(format, args, printed_chars);
	else if (*format == 'R')
		printed_chars = handle_rot13_string(args, printed_chars);
	else if (check_for_unknown_specifier(format) == 1)
		printed_chars = handle_unknown_specifier(format, printed_chars);
	return (printed_chars);
}
/**
 * Parse_flags - Handles the parsing of conversion specifiers and
 * their arguments.
 * @format: The format string to parse.
 * @options: A structure of modifier options to apply to the conversion.
 *
 * Return: A pointer to the format specifier character in the format string.
 */
const char *Parse_flags(const char *format, t_options options)
{
	int un;

	while (*format == '+' || *format == ' ' || *format == '#' ||
			*format == '0' || *format == '-' || _isdigit(*format))
	{
		if (*format == '+')
			options.plus = 1;
		else if (*format == ' ')
			options.space = 1;
		else if (*format == '#')
			options.hash = 1;
		else if (*format == '0')
			options.zero = 1;
		else if (*format == '-')
			options.minus = 1;
		format++;
	}
	un = 1;
	if (un)
		un = options.plus;
	if (*format == 'l' || *format == 'h')
	{
		if (*format == 'l')
			options.Long = 1;
		else if (*format == 'h')
			options.Short = 1;
		format++;
	}
	return (format);
}
/**
 * Parse_f - Handles the parsing of conversion specifiers and
 * their arguments.
 * @args: A va_list of arguments to parse.
 * @format: The format string to parse. 
 *
 * Return: A pointer to the format specifier character in the format string.
 */
const char *Parse_f(va_list args, const char *format)
{
	t_options options = FLAG_INIT;
	int un = 1;

	if (un)
                un = options.plus;
	Parse_flags(format, options);
	if (_isdigit(*format))
	{
		options.width = _atoi(format);
		while (_isdigit(*format))
			format++;
	}
	if (*format == '*')
	{
		options.width = va_arg(args, int);
		options.width_set = 1;
		format++;
	}
	if (*format == '.')
	{
		format++;
		if (*format == '*')
		{
			options.precision = va_arg(args, int);
			options.precision_set = 1;
			format++;
		}
		else
		{
			options.precision = 0;
			while (*format >= '0' && *format <= '9')
			{
				options.precision = options.precision * 10 + (*format - '0');
				format++;
			}
			options.precision_set = 1;
		}
	}
	return (format);
}
