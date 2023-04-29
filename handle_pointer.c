#include "main.h"
/**
 * handle_pointer - handles the p conversion specifier
 * @ptr: the void ptr containing the string to check
 * @printed_chars: the number of characters printed so far
 *
 * Return: the number of characters printed
 */

int handle_pointer(void *ptr, int printed_chars)
{
	unsigned long int p = (unsigned long int)ptr;
	char *hex = "0123456789abcdef";
	char buffer[BUFFER] = {'\0'};
	int i;
	int num_digits = 0;

	/* convert pointer address to hexadecimal string */
	do
	{
		buffer[num_digits] = hex[p & 0xF];
		p >>= 4;
		num_digits++;
	} while (p);

	/* add 0x prefix */
	buffer[num_digits++] = 'x';
	buffer[num_digits++] = '0';

	/* print hexadecimal string */
	for (i = num_digits - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
		printed_chars++;
	}

	return (printed_chars);
}
/**
 * handle_specifier - handles a single format specifier character
 *
 * @specifier: a pointer to the format specifier character
 * @args: a va_list containing the arguments for the format string
 * @printed_chars: the number of characters already printed
 *
 * Return: the number of characters printed after processing the specifier
 */
int handle_specifier(const char *specifier, va_list args, int printed_chars)
{
	void *ptr = va_arg(args, void *);

	switch (*specifier)
	{
		case 'p':
			printed_chars = handle_pointer(ptr, printed_chars);
			break;
		default:
			break;
	}
	return (printed_chars);
}

/**
 * check_for_unknown_specifier - checks if a character is a valid specifier
 * @c: the character to check
 *
 * Return: 1 if the character is a valid specifier, 0 otherwise
 */
int check_for_unknown_specifier(const char *c)
{
	const char *valid_specifiers = "cspdiouxXfFeEgGaAn%";
	int i = 0;

	while (valid_specifiers[i] != '\0')
	{
		if (valid_specifiers[i] == *c)
			return (0);
		i++;
	}
	return (1);
}

