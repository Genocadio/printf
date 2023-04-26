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
/**
 * unsigned_int - function to print unsigned int;
 * @args: argument to _printf
 * Return: number of printed digits
 */
int unsigned_int(va_list args)
{
	unsigned int num;
	unsigned int n;
	unsigned int dividor = 1;
	int i;
	int d = 0;
	int len = 0;

	num = va_arg(args, unsigned int);
	if (num == 0)
	{
		len = _putchar('0');
	}
	else
	{
		n = num;
		while (n > 0)
		{
			n /= 10;
			d++;
		}
		len += d;
		while (d > 0)
		{
			for (i = 1; i < d; i++)
			{
				dividor *= 10;
			}
			_putchar('0' + num / dividor);
			num %= dividor;
			d--;
			dividor = 1;
		}
	}
	return (len);
}
/**
 * print_octal - function to convert int to binary and print it
 * @args: argument to _printf
 * Return: number of printed digits
 */
int print_octal(va_list args)
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
		str[i++] = (num % 8) + '0';
		num /= 8;
	} while (num);
	while (--i >= 0)
	{
		_putchar(str[i]);
		l++;
	}
	return (l);
}

