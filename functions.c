#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * count - function that counts number of digits
 * @n: integer to count
 * Return: number of digits in an int
 */
int count(int n)
{
	int j = 0;

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
 * print_integer - function that prints an integer argument
 * @args: va_list containing the integer argument
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
	int arg = va_arg(args, int);
	int n = arg;
	int m = 0;
	int len = count(arg);
	char buffer[len];
	int i = 0;

	if (n < 0)
	{
		buffer[i++] = '-';
		n = -n;
	}

	while (n > 0)
	{
		int d;

		d = n % 10;
		n /= 10;
		buffer[i++] = d + '0';
	}

	while (i > 0)
	{
		write(1, &buffer[--i], 1);
	}

	return (len);
}
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
	if (s == NULL)
	{
		s = "(null)";
	}
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
