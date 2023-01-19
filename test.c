#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	check_leak(void)
{
	system("leaks --list -- a.out");
}

int main()
{
	char	*buf;
	int fd;
	int i = 0;

	fd = open("test.txt",O_RDONLY);
	while (i < 10)
	{
		buf = get_next_line(fd);
		printf("%s",buf);
		i++;
	}
//	atexit(check_leak);
}
