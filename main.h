#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
int _printf(const char *format, ...);
int count(int n);
void print_int(int n);
int _putchar(char c);
int print_integer(va_list args);
void print_char(va_list args, int *j);
void print_string(va_list args, int *j);
void print_percent(int *j);
void print_percent(int *j);
void reverse_string(char *str, int len);
void reverse_string(char *str, int len);
size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);

#endif
