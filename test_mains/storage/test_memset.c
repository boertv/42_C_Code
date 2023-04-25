#include <string.h>
#include <strings.h>
#include <stdio.h>
#include "libft.h"

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;

	if (ac > 2)
		return (0);
	if (ac == 2)
	{
	int	nb = (int) *av[1];
	
//	int	nb = -7;
	char s1[10];
	char s2[10];
	s1[3] = 0;
	printf ("1|%s|\n", (char *) memset((void *) s1, nb, 3));

	s2[3] = 0;
	printf ("2|%s|\n", (char *) ft_memset((void *) s2, nb, 3));
	}

	else
	{
		int n = 3;
		int a1[n];
		int a2[n];
		int	nb = 4;
		int	i = 0;
	
		memset (a1, nb, n * sizeof(int));
		ft_memset (a2, nb, n * sizeof(int));

		while (i < n)
		{
			if (i == 0)
				printf ("1|");
			if ( i < n - 1)
				printf ("%i ", a1[i++]);
			if (i == n - 1)
				printf ("%i|", a1[i++]);
		}
		i = 0;
		printf ("\n");
		while (i < n)
		{
			if (i == 0)
				printf ("2|");
			if ( i < n - 1)
				printf ("%i ", a2[i++]);
			if (i == n - 1)
				printf ("%i|", a2[i++]);
		}
	}
}
