#include "main.h"

/**
 * handle_unsigned - Handles printing unsigned int types
 * @args: Arguments to print
 * @buffer: Buffer to store output
 * @flags: Flags to modify output
 * @width: Width of field to print
 * @precision: Precision of field to print
 * @size: Size of integer to print
 *
 * Return: Number of bytes printed
 */
int handle_unsigned(va_list args, char *buffer,
                    __attribute__((unused)) int flags,
                    __attribute__((unused)) int width,
                    __attribute__((unused)) int precision,
                    int size)
{
    unsigned int num;
    int i = 0, j = 0;
    char binary[32] = {'\0'};

    /* Get the argument */
    if (size == 1)
        num = (unsigned char)va_arg(args, unsigned int);
    else if (size == 2)
        num = (unsigned short int)va_arg(args, unsigned int);
    else if (size == 3)
        num = va_arg(args, unsigned long int);
    else if (size == 4)
        num = va_arg(args, unsigned long long int);
    else
        num = va_arg(args, unsigned int);

    /* Convert the number to binary */
    while (num > 0)
    {
        binary[i] = (num % 2) + '0';
        num = num / 2;
        i++;
    }

    /* If the binary number is zero, store a single 0 */
    if (i == 0)
    {
        binary[i] = '0';
        i++;
    }

    /* Add null terminator to binary string */
    binary[i] = '\0';

    /* Reverse the binary string */
    j = i - 1;
    i = 0;
    while (i < j)
    {
        char tmp = binary[i];
        binary[i] = binary[j];
        binary[j] = tmp;
        i++;
        j--;
    }

    /* Copy binary string to buffer */
    i = 0;
    while (binary[i] != '\0')
    {
        buffer[i] = binary[i];
        i++;
    }

    /* Return number of bytes printed */
    return i;
}
