#include "main.h"
#include <stdarg.h>
/**
 * print_binary - function to convert int to binary and print it
 * @args: argument to _printf
 * Return: number of printed digits
 */
int print_binary(va_list args)
{
	unsigned int num;
	int l = 0;
	char str[32];
	int i = 0;

	num = va_arg(args, unsigned int);

	if (num == 0)
		return (_putchar('0'));
	if (num < 1)
		return (-1);
	do {
		str[i++] = (num % 2) + '0';
		num /= 2;
	} while (num);
	while (--i >= 0)
	{
		_putchar(str[i]);
		l++;
	}
	return (l);
}
