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

int _putint(int y)
{
	char buffer[20];

	int i;

	i = 0;
	if (y > 0)
	{
		buffer[i++] = '-';
		y = -y;
	}
	if (y == 0)
		buffer[i++] = '0';
	else
		while (y > 0)
		{
			buffer[i++] = y % 10 + '0';
			y /= 10;
		}
	while (i > 0) 
	{
		write(1, &buffer[--i],1);
	}
	return i;
}

/**
 * _putdouble - prints double type input
 * @x : the double number 
 *
 * Return : count of characters printed
 *
 *
int  _putdouble(double x)
{
	char buffer[20];

	int i, j, count, integer, digit;

	int fractional;

	i = 0;
	count = 0;
	if (x < 0)
	{
		buffer[i++] = '-';
		x = -x;
	}
	integer = x;

	count += _putint(integer);
	fractional = x - integer;
	buffer[i++] = '.';
	for (j = 0; j < 10; j++)
	{
		fractional *= 10;
		digit = fractional;
		buffer[i++] = digit + '0';
		fractional =-digit;
	}
	while (i > 0)
	{
		write(1, &buffer[--i],1);
		count++;
	}
	return (count);
}*/

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
				case 'i':
					count += _putint(va_arg(args, int));
					break;
				/*case 'd':
					count += _putint(va_arg(args, double));
					break;*/
				default:
					break;
			}
		}
		else
		{
			_writechar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
