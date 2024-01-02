#include "get_next_line.h"


# include <stdio.h>
# include <fcntl.h>

int main()
{
    int fd = open("get_next_line.c", O_RDONLY);

	char *line;
	// int nb = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("line () => %s", line);
		free(line);
	}
	close(fd);
	return (0);
}
