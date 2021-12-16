#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

static void put_str(char *s, int *size)
{
	if(!s)
		*size += write(1, "(null)", 6);
	else
		while(*s)
			*size += write(1, s++, 1);
}

static void put_hex(unsigned int i, int *size)
{
	char *base = "0123456789abcdef";
	if(i / 16 > 0)
	{
		put_hex(i / 16, size);
		*size += write(1, &base[i % 16], 1);
	}
	else
		*size += write(1, &base[i], 1);
}

static void put_nbr(int i, int *size)
{
	char c;
	if (i == -2147483648)
	{
		*size += write(1, "-2147483648", 11);
		return ;
	}
	if (i < 0)
	{
		*size += write(1, "-", 1);
		i *= -1;
	}
	if(i / 10)
		put_nbr(i / 10, size);
	c = i % 10 + 48;
	*size += write(1, &c, 1);
}

int ft_printf(const char *str, ...)
{
	int size = 0;
	int i = 0;
	va_list op;
	va_start(op, str);
	while(str[i])
	{
		if(str[i++] != '%')
			size += write(1, &str[i - 1], 1);
		else 
		{
			if (str[i] == 's')
				put_str(va_arg(op, char *), &size);
			else if (str[i] == 'd')
				put_nbr(va_arg(op, int), &size);
			else if (str[i] == 'x')
				put_hex(va_arg(op, unsigned int), &size);
			i++;
		}
	}
	return(size);
}
