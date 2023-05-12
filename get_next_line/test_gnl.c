#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main(void)
{
	int fd = open("nbs.txt", O_RDONLY);
	char *output = "blablablablablablablablablablablablablablablablabla";

	printf("\n\t\t\t-----fd = |%i|-----\n\n", fd);
	while (output)
	{
		output = get_next_line(fd);
		printf(">>>>> |%s| <<<<<\n\n", output);
	}
	close (fd);
}

// char	*ft_hupla(const char *str)
// {
// 	char *res = malloc(27);
// 	if (!res)
// 		return (NULL);
// 	int i = 0;
// 	while (str[i])
// 	{
// 		res[i] = str[i];
// 		i++;
// 	}
// 	return (res);
// }

// int	main()
// {
// 	char *test = ft_hupla("abcdefghijklmnopqrstuvwxyz");
// 	// int fd = open("nbs.txt", O_RDONLY);
// 	// printf("\nbytes read = %zd\n", read(fd, test, 5));
// 	// printf("buffer = %s\n\n", test);

// 	free(test);
// }
