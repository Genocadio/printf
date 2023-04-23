#ifndef MAIN_h
#define MAIN_H

#include <stdarg.h>
int _printf(const char *format, ...);
int count(va_list args);
void print_int(va_list args);
int _putchar(char c);

#endif
