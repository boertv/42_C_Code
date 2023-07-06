#include "pipex.h"

// int	main(int ac, char *av[])
// {
// 	char	**arr;

// 	if (ac < 2)
// 		return (1);
// 	arr = ft_split(av[1], ' ');
// 	if (!arr)
// 		return (1);
// 	if (!execve("/bin/ls", arr, NULL))
// 		perror("execve failed");
// }

int	main()
{
	char	**c;
	void	*v;
	char	**n;

	c = NULL;
	v = c;
	n = v;
	printf("c = %p, v = %p, n = %p\n", c, v, n);
	printf("c: %s | n: %s\n", c[0], n[0]);
	free(c);
}
