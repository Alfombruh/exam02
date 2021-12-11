#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int ft_str(char *arg)
{
	int size;

	size = 0;
	if (arg == NULL)
		return (write(1, "(null)", 6));
	while(arg[size])
		size += write(1, &arg[size], 1);
	return (size);
}

int ft_base(int i, int base)
{
	char	*str;
	int 	num;
	int		size;
	int 	j;

	size = 0;
	if (i == 0)
		return(write(1, "0", 1));
	if (i < 0)
	{
		size += write(1, "-", 1);
		i *= -1;
	}
	num = i;
	while (num != 0)
	{
		num /= base;
		size++;
	}
	j = size;
	str = malloc(size + 1);
	str[j] = '\0';
	while (i != 0)
	{
		if ((i % base) < 10)
			str[j - 1] = (i % base) + 48;
		else
			str[j - 1] = (i % base) + 87;
		j--;
		i /= base;
	}
	write(1, str, size);
	free (str);
	return (size);
}

int	ft_args(char *str, va_list op)
{
	int count;

	count = 0;
	if (*str == 'd')
		count = ft_base(va_arg(op, int), 10);
	if (*str == 'x')
		count = ft_base(va_arg(op, int), 16);
	if (*str == 's')
		count = ft_str(va_arg(op, char *));
	return (count);
}

int ft_printf(char *format, ...)
{
	va_list op;
	int size;

	size = 0;
	va_start(op, format);
	while (*format)
	{
		if (*format == '%' && *++format != '%')
			size += ft_args(format++, op);
		else
		{
			size += write(1, format, 1);
			format++;
		}
	}
	va_end(op);
	return (size);
}
