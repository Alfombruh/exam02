#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*get_next_line(int fd);

int main()
{
	char	*str;
	int		fd;
	int		scan;

	fd = open("texto.txt", O_RDONLY);
	printf("---type 0 then enter if you wanna see the next line---\n ---type 1 and then enter if not---\n");
	while(1)
	{
		str = get_next_line(fd);
		scanf("%d", &scan);
		if (scan == 0)
			printf("%s", str);
		else
			return(0);

	}
	return (0);
}
