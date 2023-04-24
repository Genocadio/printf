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

	i = 0;
	if (sign)
		buffer[i++] = '-';

	while (n > 0)
	{
		int d;

		d = n % 10;
		n /= 10;
		buffer[i++] = d + '0';
	}
	buffer[i] = '\0';

	reverse_string(buffer, i);

	bytes_written = write(1, buffer, i);
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
	char *s = va_arg(args, char*);
	int bytes_written;
	int len = _strlen(s);
	char *buffer = malloc(len + 1);

	if (s == NULL)
		s = "(null)";
	if (buffer == NULL)
		return;

	_strcpy(buffer, s);

	bytes_written = write(1, buffer, len);
	if (bytes_written > 0)
		*j += bytes_written;
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
