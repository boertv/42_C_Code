#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"


char	fmapi(unsigned int i, char c)
{
	(void) c;
	return (i + '0');
}

void	fiteri(unsigned int i, char *c)
{
	*c = i + '0';
}

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;

	if (!ft_strncmp(av[1], "strlen", 7))
	{
		printf ("c |%lu|\n", strlen(av[2]));
		printf ("t |%lu|\n", ft_strlen(av[2]));
	}
	else if (!ft_strncmp(av[1], "strlcpy", 8))
	{
		unsigned long	l = ft_atoi(av[3]);
		int	n = strlen(av[2]) + 1;
		char	buf1[n];
		char	buf2[n];
		printf ("c |%lu: ", strlcpy(buf1, av[2], l));
		printf ("%s|\n", buf1);
		printf ("t |%lu: ", ft_strlcpy(buf2, av[2], l));
		printf ("%s|\n", buf2);
	}
	else if (!ft_strncmp(av[1], "strlcat", 8))
	{
		unsigned long	l = ft_atoi(av[4]);
		char	buf1[50];
		char	buf2[50];
		strcpy (buf1, av[2]);
		strcpy (buf2, av[2]);
		printf ("c |%lu: ", strlcat(buf1, av[3], l));
		printf ("%s|\n", buf1);
		printf ("t |%lu: ", ft_strlcat(buf2, av[3], l));
		printf ("%s|\n", buf2);
	}
	else if (!ft_strncmp(av[1], "strchr", 7))
	{
		int	c = (int) *av[3];
		printf ("c |%s|\n", strchr(av[2], c));
		printf ("t |%s|\n", ft_strchr(av[2], c));
	}
	else if (!ft_strncmp(av[1], "strrchr", 8))
	{
		int	c = (int) *av[3];
		printf ("c |%s|\n", strrchr(av[2], c));
		printf ("t |%s|\n", ft_strrchr(av[2], c));
	}
	else if (!ft_strncmp(av[1], "strncmp", 8))
	{
		int	n = ft_atoi(av[4]);
		printf ("c |%i|\n", strncmp(av[2], av[3], n));
		printf ("t |%i|\n", ft_strncmp(av[2], av[3], n));
	}
	else if (!ft_strncmp(av[1], "strnstr", 8))
	{
		int	l = ft_atoi(av[4]);
		printf ("c |%s|\n", strnstr(av[2], av[3], l));
		printf ("t |%s|\n", ft_strnstr(av[2], av[3], l));
	}
	else if (!ft_strncmp(av[1], "strdup", 7))
	{
		char	*s1 = strdup(av[2]);
		char	*s2 = ft_strdup(av[2]);
		printf ("c |%s|\n", s1);
		printf ("t |%s|\n", s2);
		free (s1); free (s2);
	}
	else if (!ft_strncmp(av[1], "substr", 7))
	{
		if (ac != 5)
		{
			printf("please provide these arguments:\n[string], [start index], [length]\n");
			return (0);
		}
		printf("|%s|\n", ft_substr(av[2], ft_atoi(av[3]), ft_atoi(av[4])));
	}
	else if (!ft_strncmp(av[1], "strjoin", 8))
	{
		if (ac != 4)
		{
			printf("please provide two strings\n");
			return (0);
		}
		printf("|%s|\n", ft_strjoin(av[2], av[3]));
	}
	else if (!ft_strncmp(av[1], "strtrim", 8))
	{
		if (ac != 4)
		{
			printf ("please provide a string and a set of characters to be trimmed\n");
			return (0);
		}
		printf("|%s|\n", ft_strtrim(av[2], av[3]));
	}
	else if (!ft_strncmp(av[1], "split", 6))
	{
		if (ac != 4)
		{
			printf ("please provide a string and a delimiter chararcter");
			return (0);
		}
		char	**s = ft_split(av[2], *av[3]);
		if (!s)
			return (0);
		size_t	i = 0;
		while (*(s + i))
		{
			printf ("|%s|\n", *(s + i));
			free(*(s + i));
			i++;
		}
		printf("%s\n", *(s + i));
		free(s);
	}
	else if (!ft_strncmp(av[1], "atoi", 5))
	{
		int	n1 = atoi(av[2]);
		int	n2 = ft_atoi(av[2]);
		printf("o: |%i|\nc: |%i|\n", n1, n2);
	}
	else if (!ft_strncmp(av[1], "itoa", 5))
	{
		char	*s = ft_itoa(ft_atoi(av[2]));
		printf("|%s|\n", s);
		free(s);
	}
	else if (!ft_strncmp(av[1], "strmapi", 8))
	{
		char	*s = ft_strmapi(av[2], *(fmapi));
		printf ("|%s|\n", s);
		free(s);
	}
	else if (!ft_strncmp(av[1], "striteri", 9))
	{
		char	*s = ft_strdup(av[2]);
		ft_striteri(s, (*fiteri));
		printf ("|%s|\n", s);
		free (s);
	}
	else
		printf("please provide a function to run\n");
}
