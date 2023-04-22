#include "main.h"
#include <stdarg.h>
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
	char c;
	char *s;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
					c = (cahr) va_arg(args, int);
					write(1, &c, 1);
					j++;
					break;
					}
				case 's':
					{
						s = va_arg(args, char *);
						while (*s)
						{
							write(1, s, 1);
							s++;
							j++;
						}
						break;
					}
				case '%':
					{
						write(1, "%", 1);
						j++;
						break;
					}
				default:
					{
						return (-1);
					}
			}
		}
		else
		{
			write(1, format, 1);
			j++;
		}
		format++;
	}
	va_end(args);
	return (j);
}
