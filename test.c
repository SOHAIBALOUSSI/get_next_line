#include "get_next_line.h"
#include <limits.h>
int main()
{
	int fd = open("batman.txt", O_RDWR);
	char buffer[50];
	read(fd, buffer, sizeof(buffer));

	printf("%s", buffer);
	return (0);
}