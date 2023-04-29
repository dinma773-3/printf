#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define FLAG_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define BUFFER 1024

typedef struct s_options
{
    int plus;
    int space;
    int hash;
    int Long;
    int Short;
    int precision;
    int precision_set;
    int width;
    int width_set;
    int zero;
    int minus;
} t_options;

/* print.c file*/
int _printf(const char *format, ...);
int handle_format(va_list args, const char *format, t_options options, int printed_chars);
int hand_help(const char *format, int printed_chars, va_list args);
const char *Parse_flags(const char *format, t_options options);
const char *Parse_f(va_list args, const char *format);
/*Conversion & number.c file */
int _atoi(const char *s);
int _isdigit(int c);
int count_digits(char *buffer);
int print_number(char *buffer, t_options options);

/* conversion & string */
int int_to_buffer(int n, char *buffer, int buffer_size);
int print_padding(int width, int printed_chars, char padding_char);
int handle_unknown_specifier(const char *format, int printed_chars);
int handle_reversed_string(va_list args, int printed_chars);

/* Handle_specifier.c */
int handle_integer(va_list args, int printed_chars, t_options op);
int print_integer(char *buffer, t_options op, int len, int printed_chars);
int handle_binary(va_list args, int printed_chars, t_options op);
int h_unsigned_int(va_list args, int printed_chars, t_options op);
int handle_octal(va_list args, int printed_chars, t_options op);

/* Handle_Hexa.c */
int handle_low_hexa(va_list args, int printed_chars, t_options op);
int handle_upper_hexa(va_list args, int printed_chars, t_options op);
int handle_string(va_list args, int printed_chars);
int print_hexa(unsigned int n, const char *charset, int width);

/* Handle_pointer.c */
int handle_specifier(const char *specifier, va_list args, int printed_chars);
int handle_pointer(void *ptr, int printed_chars);
int check_for_unknown_specifier(const char *c);
int handle_rot13_string(va_list args, int printed_chars);

#endif
