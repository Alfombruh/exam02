#include <stdio.h>
int ft_printf(char *format, ...);

int main()
{
	ft_printf("ft_printf   int:%d hex:%x\n", 1279, 12736);
	printf("printf   int:%d hex:%x\n", 1279, 12736);
	ft_printf("ft_printf   int:%d hex:%x\n", -20397, 102973);
	printf("printf   int:%d hex:%x\n", -20397, 102973);
	ft_printf("ft_printf   int:%d hex:%x\n", -94820, 237);
	printf("printf   int:%d hex:%x\n", -94820, 237);
	ft_printf("ft_printf   int:%d hex:%x\n", 7593, 4593);
	printf("printf   int:%d hex:%x\n", 7593, 4593);
	ft_printf("ft_printf   int:%d hex:%x\n", 0, 0);
	printf("printf   int:%d hex:%x\n", 0, 0);
	return (0);
}
