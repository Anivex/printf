#include "main.h"

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int _puts(char *s)
{
    int i = 0;

    while (s[i])
        _putchar(s[i++]);
    return (i);
}

int _strlen(const char *s)
{
    int i = 0;

    while (s[i])
        i++;

    return (i);
}


int _printf(const char *format, ...)
{
    va_list ap;
    /*int (*f)(void);*/
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
            }

        }
        else
        {
            _putchar(format[i]);
            numc++;
        }
    }


    va_end(ap);
    return numc;
}

