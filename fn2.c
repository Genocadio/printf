#include "main.h"
#include <unistd.h>
/**
 * reverse_string - function to reverse string
 * @str: string to reverse
 * @len: length of string
 * Return: void
 */
void reverse_string(char *str, int len)
{
	int i;
	int j;

	if (str == NULL)
		return;
	i = 0;
	j = len - 1;
	while (i < j)
	{
		char temp;

		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}
