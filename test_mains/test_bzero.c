#include <stdio.h>
#include <strings.h>
#include "libft.h"

int	main(void)
{
	int a1[] = {-3, -4, 3, 4, 0};
	int a2[] = {-3, -4, 3, 4, 0};

	char b1[] = "abcdef";
	char b2[] = "abcdef";

	unsigned c1[] = {0, 1, 2, 3, 0};
	unsigned c2[] = {0, 1, 2, 3, 0};

	bzero (a1, 4 * sizeof(int)); bzero (b1, 6 * sizeof(char)); bzero (c1, 4 * sizeof(unsigned));
	ft_bzero (a2, 4 * sizeof(int)); ft_bzero (b2, 6 * sizeof(char)); ft_bzero (c2, 4 * sizeof(unsigned));

	int n = 5;
	int	i = -1;

	while (++i < n)
		printf("%i ", a1[i]);
	printf("\n");
	i = -1;
	while (++i < n)
		printf("%i ", a2[i]);
	printf("\n");

	printf("%s\n%s\n", b1, b2);

	i = -1;
	while (++i < n)
		printf("%u ", c1[i]);
	printf("\n");
	i = -1;
	while (++i < n)
		printf("%u ", c2[i]);
	printf("\n");
}
