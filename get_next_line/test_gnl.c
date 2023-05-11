#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int fd = open("nbs.txt", O_RDONLY);
	printf("\nfd = %i\n\n", fd);
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	printf("buffer = %s\n\n", get_next_line(fd));
	close (fd);
}
