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

/**
 * _strlen - count length of format.
 *
 * @s: format.
 *
 * Return: length of format.
 */

int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (-1);
	while (s[i])
		i++;

	return (i);
}

int specifier(char c, va_list ap)
{
	int num = 0;

	switch (c)
	{
		case 'c':
			num += _putchar(va_arg(ap, int));
			break;
		case 's':
			num += _puts(va_arg(ap, char *));
			break;
		case '%':
			num += _putchar('%');
			break;
		default:
			num += _putchar('%');
			num += _putchar(c);
			break;
	}

	return (num);
}

/**
 * _printf - is the C language function to do format-ted printing.
 *
 * @format: string.
 *
 * Return: number of character printed.
 */


int _printf(const char *format, ...)
{
	va_list ap;
	int i, len, numc = 0;

	len = _strlen(format);
	if (len == -1)
		return (-1);
	va_start(ap, format);
	for (i = 0; i < len; i++)
	{

		if (format[i] == '%')
		{
			i++;
			if (format[i])
				numc += specifier(format[i], ap);
			else
				return (-1);
		}
		else
			numc += _putchar(format[i]);
	}
	va_end(ap);
	return (numc);
}
