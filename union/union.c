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

void ft_union(char *str, char *skr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (str[i] || skr[j])
	{
		if (!str[i])
		{
			if(!ft_dups(skr, j) && ft_strchr(skr[j], str))
				write(1, &skr[j], 1);
			j++;
		}
		else
		{	if (!ft_strchr(str[i], str) && !ft_dups(str, i)) 
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
		return (write(1, "\n", 1));
	else if (argc != 3)
		return (1);
	ft_union(argv[1], argv[2]);
	return (0);
}
