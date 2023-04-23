#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * print_char - function to print char
 * @args: argument to printf
 * @j: number of printed charcters
 * Return: void
 */
void print_char(va_list args, int *j)
{
	char c;

	c = (char) va_arg(args, int);
	write(1, &c, 1);
	(*j)++;
}
/**
 * print_string - function to print string
 * @args: argument to printf
 * @j: number of printed charcters
 * Return: void
 */
void print_string(va_list args, int *j)
{
	char *s;

	s = va_arg(args, char *);
	while (*s)
	{
		write(1, s, 1);
		s++;
		(*j)++;
	}
}
/**
 * print_percent - function to print percent
 * @j: number of printed charcters
 * Return: void
 */
void print_percent(int *j)
{
	write(1, "%", 1);
	(*j)++;
}
/**
 * _printf - function that works like printf function
 * @format:  is a character string
 * Return: number of charcters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int j;

	va_start(args, format);
	for (j = 0; *format; format++)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_char(args, &j);
					break;
				case 's':
					print_string(args, &j);
					break;
				case '%':
					print_percent(&j);
					break;
				case 'i':
				case 'd':
					{
						print_int(args);
						j += count(args);
						break;
					}
				default:
					return (-1);
			}
		}
		else
		{
			write(1, format, 1);
			j++;
		}
	}
	va_end(args);
	j -= 1;
	return (j);
}
