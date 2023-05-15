#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac < 2)
		return (0);

	int	n = 0;
	while (av[++n])
	{
		int fd = open(av[1], O_RDONLY);
		char *output = "blablablablablablablablablablablablablablablablabla";

		printf("\n\t\t\t-----fd = |%i|-----\n", fd);
		while (output)
		{
			output = get_next_line(fd);
			printf(">>>>> |%s| <<<<<\n", output);
		}
		printf("\n\tFIN\n\n");
		close (fd);
	}
}
