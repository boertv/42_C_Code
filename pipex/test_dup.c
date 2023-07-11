#include "pipex.h"

static int	ft_dup_shit(int fd1, int fd2)
{
	fd1 = dup2(fd1, fd2);
	return (fd1);
}

//"test.txt becomes the new stdin"
int	main(void)
{
	int	temp;
	int	fd;
	char	buf[51];

	fd = 5;
	temp = open("test.txt", O_RDONLY);
	if (temp == -1)
		exit(EXIT_FAILURE);
	fd = ft_dup_shit(temp, STDIN_FILENO);
	close(temp);
	printf("fd = %i, temp = %i\n", fd, temp);
	if (fd == -1)
		exit(EXIT_FAILURE);
	temp = read(fd, buf, 50);
	buf[temp] = 0;
	printf("%s\n", buf);
	close(fd);
}
