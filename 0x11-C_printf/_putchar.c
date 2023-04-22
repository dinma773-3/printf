#include "main.h"
#include <unistd.h>

int _putchar(int c)
{
	return write(1, &c, 1); /*print a single character to the stdout*/
}
