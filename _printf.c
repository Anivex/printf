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

	while (s[i])
		i++;

	return (i);
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

	va_start(ap, format);

	for (i = 0, len = _strlen(format); i < len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					numc += _putchar(va_arg(ap, int));
					break;
				case 's':
					numc += _puts(va_arg(ap, char *));
					break;
				case '%':
					numc += _putchar('%');
					break;
			}

		}
		else
		{
			_putchar(format[i]);
			numc++;
		}
	}


	va_end(ap);
	return (numc);
}

