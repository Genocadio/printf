#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
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
						j += print_integer(args);
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
	printf("%d \n", j);
	return (j);
}
