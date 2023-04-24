#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
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
	int digits = count(arg);
	int sign = 0;
	char *buffer;
	int i;
	int bytes_written;

	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	buffer = malloc(digits + sign + 1);
	if (buffer == NULL)
		return (-1);
	i = sign;
	if (sign)
		buffer[0] = '-';
	while (n > 0)
	{
		int d;

		d = n % 10;
		n /= 10;
		buffer[i++] = d + '0';
	}
	buffer[i] = '\0';

	reverse_string(buffer + sign, i - sign);

	if (sign)
		bytes_written = write(1, buffer, digits);
	else
	{
		write(1, buffer, digits);
		bytes_written = digits;
	}
	free(buffer);
	return (bytes_written);
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
