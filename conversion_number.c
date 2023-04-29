#include "main.h"
/**
 * print_number - prints formatted number
 * @buffer: buffer containing formatted number
 * @options: formatting options
 *
 * Return: number of characters printed
 */
int print_number(char *buffer, t_options options)
{
	int len = count_digits(buffer);
	int printed_chars = 0;

	if (options.plus)
		write(1, "+", 1);
	else if (options.space)
		write(1, " ", 1);
	while (len--)
	{
		write(1, &buffer[len], 1);
		printed_chars++;
	}
	return (printed_chars);
}
/**
 * count_digits - Counts the number of digits in a string
 *
 * @buffer: Pointer to the string to count digits in
 *
 * Return: The number of digits in the string
 */
int count_digits(char *buffer)
{
	int i = 0;

	while (buffer[i])
		i++;
	return (i);
}
/**
 *  _isdigit - checking a int is digit
 * @c: is the in to be checked
 * Return: 1 if int is digit, otherwise 0
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
/**
 * _atoi - convert a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if no number is found
 */
int _atoi(const char *s)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
			result = result * 10 + (s[i] - '0');
		else if (result > 0)
		{
			/* we've found the end of the number, so break */
			break;
		}
		i++;
	}
	return (sign * result);
}
