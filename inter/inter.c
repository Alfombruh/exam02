#include <unistd.h>

int ft_dups(char *str, char c, int i, int read_full)
{
	int j = 0;
	while((j < i|| read_full) && str[j])
		if(str[j++] == c)
			return (1);
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;
	if(argc == 3)
	{
		while(argv[1][i])
		{
			if(!ft_dups(argv[1], argv[1][i], i, 0))
				if(ft_dups(argv[2], argv[1][i], i, 1))
					write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
