#include "main.h"
#include <unistd.h>
#include <stddef.h>
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
/**
* _strlen - function to count length of string
* @s: string to count its length
* Return: size of s
*/
size_t _strlen(const char *s)
{
	const char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return (p - s);
}
#include "main.h"
/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
}
