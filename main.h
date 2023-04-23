#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _printf(const char *format, ...);
int count(int n);
void print_int(int n);
int _putchar(char c);
int print_integer(va_list args);
void print_char(va_list args, int *j);
void print_string(va_list args, int *j);
void print_percent(int *j);
void print_percent(int *j);

#endif
