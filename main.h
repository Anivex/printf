#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>



int _puts(char *s);
int _putchar(char c);
int _strlen(const char *s);
int _printf(const char *format, ...);
int specifier(char c, va_list ap);
#endif
