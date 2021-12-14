#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int put_nbr(int nbr)
{
	char c;
	int size = 0;
	if (nbr == -2147483648)
	{
		size += write(1, "-2147483648", 11);
		return (size);
	}
	if (nbr < 0)
	{
		size += write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr / 10)
		size += put_nbr(nbr / 10);
	c = nbr % 10 + 48;
	size += write(1, &c, 1);
	return (size);
}

int put_hex(int nbr)
{
	int size = 0;
	char *base = "0123456789abcdef";
	if(nbr / 16 > 0)
	{
		size += put_hex(nbr / 16);
		size += write(1, &base[nbr % 16], 1);
		return (size);
	}
	size += write(1, &base[nbr], 1);
	return (size);
}

int ft_printf(const char *str, ...)
{
	va_list op;
	int size = 0;
	int i = 0;
	va_start(op, str);
	while(str[i])
	{
		if(str[i] != '%')
			size += write(1, &str[i++], 1);
		else
		{
			++i;
			if(str[i] == 'd')
				size += put_nbr(va_arg(op, int));
			else if(str[i] == 'x')
				size += put_hex(va_arg(op, int));
			i++;
		}
	}
	va_end(op);
	return (size);
}

int main()
{
	printf("first one:%d\n",ft_printf("%x: ", 0));
	printf("first one:%d\n",printf("%x: ", 0));
	return (0);
}
