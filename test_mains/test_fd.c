#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		printf("please provide a function name and an argument");
		return (0);
	}
	int	fd = open("test.txt", O_RDWR | O_EXCL | O_CREAT, 0000777);
	if (fd < 0)
	{
		printf("test failed, file could not be created\n");
		return (0);
	}
	if (!ft_strncmp(av[1], "putchar", 8))
	{
		ft_putchar_fd(*av[2], fd);
	}
	else if (!ft_strncmp(av[1], "putstr", 7))
	{
		ft_putstr_fd(av[2], fd);
	}
	else if (!ft_strncmp(av[1], "putendl", 8))
	{
		ft_putendl_fd(av[2], fd);
	}
	else if (!ft_strncmp(av[1], "putnbr", 7))
	{
		int	nbr = ft_atoi(av[2]);
		ft_putnbr_fd(nbr, fd);
	}
	close(fd);
	fd = open("test.txt", O_RDWR);
	if (fd < 0)
	{
		printf("test failed, file could not be opened in step 2");
		return (0);
	}
	char	buf[50];
	size_t	r = read(fd, buf, 50);
	if (r < 1)
	{
		printf("test failed, file could not be read\n");
		return (0);
	}
	write(1, "|", 1);
	if (write(1, buf, r) < 1)
	{
		printf("test failed, buffer could not be written\n");
		return (0);
	}
	printf("|\n---end of test---\n");
	close(fd);
	if (remove("test.txt") < 0)
		printf("test file could not be deleted\n");
}
