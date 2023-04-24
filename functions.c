#include "main.h"
/**
 * print_char - function to print char
 * @arg: argument to printf
 * Return: number of printed charcters
 */
int print_char(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}
/**
 * print_string - function to print string
 * @arg: argument to printf
 * Return: number of printed charcters
 */
int print_string(va_list arg)
{
	int i;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @arg: arguments to printf
 * Return: number of printed strings.
 */
int print_percent(__attribute__((unused))va_list arg)
{
	_putchar('%');
	return (1);
}
