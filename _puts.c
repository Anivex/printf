#include "main.h"

/**
 * _putchar - print character.
 *
 * @c: char.
 *
 * Return: 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints string.
 *
 * @s: string.
 *
 * Return: number of character.
 */
int _puts(char *s)
{
	int i = 0;

	if (!s)
	{
		_puts("(null)");
		return (6);
	}
	while (s[i])
		_putchar(s[i++]);
	return (i);
}
