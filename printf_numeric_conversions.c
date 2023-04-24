#include "main.h"

/**
 * print_u - prints an unsigned integer in decimal notation
 * @args: arguments list containing unsigned integer to print
 * Return: number of digits printed
 */
int print_u(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1, remainder = n;
	int num_digits = 0;

	while (remainder / divisor > 9)
		divisor *= 10;

	while (divisor != 0)
	{
		_putchar('0' + remainder / divisor);
		remainder %= divisor;
		divisor /= 10;
		num_digits++;
	}

	return (num_digits);
}

/**
 * print_o - prints an unsigned integer in octal notation
 * @args: arguments list containing unsigned integer to print
 * Return: number of digits printed
 */
int print_o(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	unsigned int divisor = 1, remainder = n;
	int num_digits = 0;

	while (remainder / divisor > 7)
		divisor *= 8;

	while (divisor != 0)
	{
		_putchar('0' + remainder / divisor);
		remainder %= divisor;
		divisor /= 8;
		num_digits++;
	}

	return (num_digits);
}

/**
 * print_x - prints an unsigned integer in hexadecimal notation (lowercase)
 * @args: arguments list containing unsigned integer to print
 * Return: number of digits printed
 */
int print_x(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789abcdef";
	unsigned int divisor = 1, remainder = n;
	int num_digits = 0;

	while (remainder / divisor > 15)
		divisor *= 16;

	while (divisor != 0)
	{
		_putchar(hex_digits[remainder / divisor]);
		remainder %= divisor;
		divisor /= 16;
		num_digits++;
	}

	return (num_digits);
}

/**
 * print_X - prints an unsigned integer in hexadecimal notation (uppercase)
 * @args: arguments list containing unsigned integer to print
 * Return: number of digits printed
 */
int print_X(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex_digits[] = "0123456789ABCDEF";
	unsigned int divisor = 1, remainder = n;
	int num_digits = 0;

	while (remainder / divisor > 15)
		divisor *= 16;

	while (divisor != 0)
	{
		_putchar(hex_digits[remainder / divisor]);
		remainder %= divisor;
		divisor /= 16;
		num_digits++;
	}

	return (num_digits);
}
