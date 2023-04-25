#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
#include <stdlib.h>




/**
 *_writechar - prints char
 *@c: pointer to char
 *Return: character
 */
int _writechar(char c)
{
	return (write(1, &c, 1));
}

/**
 *_puts - prints strings
 *@str: pointer to string
 *Return: length of string
 */

int _puts(char *str)
{
	int len = 0;

	while (*str != '\0')
	{
		_writechar(*str);
		str++;
		len++;
	}
	return (len);
}


/**
 *_printf - prints c, s and %
 *@format: pointer to  character string
 *Return: length of string
 */

int _printf(const char *format, ...)
{
	va_list args;

	int count;

	va_start(args, format);

	count = 0;

	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_writechar(va_arg(args, int));
					count++;
					break;
				case 's':
					count += _puts(va_arg(args, char*));
					break;
				case '%':
					_writechar('%');
					count++;
					break;
				default:
					break;
			}
		}
		else
		{
			_writechar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
