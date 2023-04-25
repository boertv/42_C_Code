#include <stdio.h>
#include "libft.h"
#include <ctype.h>

int	main(int ac, char *av[])
{
	int		nb = (int) *av[1];

	if (ac != 3)
		printf ("expected 2 arguments\n");
	else if (*(av[2] + 2) == 'p')
	{
		printf ("%i\n", ft_isalpha(nb));
		printf ("%i\n", isalpha(nb));
	}
	else if (*(av[2] + 2) == 'g')
	{
		printf ("%i\n", ft_isdigit(nb));
		printf ("%i\n", isdigit(nb));
	}
	else if (*(av[2] + 2) == 'n')
	{
		printf ("%i\n", ft_isalnum(nb));
		printf ("%i\n", isalnum(nb));
	}
	else if (*(av[2] + 2) == 'c')
	{
		printf ("%i\n", ft_isascii(nb));
		printf ("%i\n", isascii(nb));
	}
	else if (*(av[2] + 2) == 'i')
	{
		printf ("%i\n", ft_isprint(nb));
		printf ("%i\n", isprint(nb));
	}
	else
		printf ("input error\n");
}
