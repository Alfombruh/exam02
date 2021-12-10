#include <unistd.h>

int ft_dups(char *str, int i)
{
	char c;

	c = str[i];
	while (--i >= 0)
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

int ft_strchr(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (0);
		str++;
	}
	return (1);
}

void ft_inter(char *str, char *skr)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], skr))
		{
			if(!ft_dups(str, i))	
				write(1, &str[i], sizeof(char));
		}
		i++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (write(1, "\n", 1));
	else if (argc != 3)
		return (1);
	ft_inter(argv[1], argv[2]);
	return (0);
}
