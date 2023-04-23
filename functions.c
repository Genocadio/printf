#include "main.h"
#include <stdarg.h>
/**
 * count - function that counts number of digits
 * @args: argument to _printf
 * Return: number of digits in an int
 */
int count(va_list args)
{
	va_list args_copy;
	int n;
	int j;

	va_copy(args_copy, args);
	n = va_arg(args_copy, int);
	va_end(args_copy);
	if (n < 0)
	{
		j++;
		n = -n;
	}

	if (n == 0)
		j++;
	else
	{
		while (n > 0)
		{
			j++;
			n /= 10;
		}
	}
	return (j);
}
/**
 * print_int - function to print integer
 * @args: argument  to _printf
 * Return:void
 */
void print_int(va_list args)
{
	int n;
	int m = 0;

	n = va_arg(args, int);
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (n > 0)
	{
		int d;

		d = n % 10;
		n /= 10;
		m = m * 10 + d;
	}
	while (m != 0)
	{
		int z;

		z = m % 10;
		_putchar(z + '0');
		m /= 10;
	}
}
