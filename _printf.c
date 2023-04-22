#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
  if (*buff_ind > 0)
    write(1, &buffer[0], *buff_ind);

  *buff_ind = 0;
}

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
  va_list list;
  int print_char = 0, buff_ind = 0, i;
  char buffer[BUFF_SIZE];
  char *string;
  unsigned int j;

  va_start(list, format);

  if (format == NULL)
    return (-1);

  for (i = 0; format[i] != '\0'; i++)
    {
      if (format[i] != '%')
	{
	  buffer[buff_ind++] = format[i];
	  if (buff_ind == BUFF_SIZE)
	    {
	      print_buffer(buffer, &buff_ind);
	      print_char += buff_ind;
	    }
	  else
	    {
	      print_char++;
	    }
	}
      else
	{
	  print_buffer(buffer, &buff_ind);
	  i++;
	  switch (format[i])
	    {
	    case 'c':
	      write(1, &va_arg(list, int), 1);
	      print_char++;
	      break;
	    case 's':
	      string = va_arg(list, char *);
	      if (string == NULL)
		string = "(null)";
	      while (*string != '\0')
		{
		  write(1, string, 1);
		  string++;
		  print_char++;
		}
	      break;
	    case '%':
	      write(1, &format[i], 1);
	      print_char++;
	      break;
	    case 'b':
	      n = va_arg(list, unsigned int);
	      print_binary(n, &buff_ind, buffer);
	      print_char += buff_ind;
	      break;
	    default:
	      write(1, "%", 1);
	      print_char++;
	      if (format[i] != '\0')
		{
		  write(1, &format[i], 1);
		  print_char++;
		}
	      break;
	    }
	}
    }
  print_buffer(buffer, &buff_ind);
  va_end(list);
  return (print_char);
}

/**
 * print_binary - Convert and print a number as binary
 * @n: The number to convert
 * @buff_ind: Pointer to the current index in the buffer
 * @buffer: The buffer to store the printed string
 */
void print_binary(unsigned int n, int *buff_ind, char buffer[])
{
  if (j > 1)
    print_binary(j >> 1, buff_ind, buffer);

  if (*buff_ind == BUFF_SIZE)
    {
      print_buffer(buffer, buff_ind);
    }

  buffer[(*buff_ind)++] = (j & 1) + '0';
}
