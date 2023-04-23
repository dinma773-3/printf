#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int handle_binary(va_list args);
int _printf(const char *format, ...);
int handle_integer(va_list args, int printed_chars);

#endif
