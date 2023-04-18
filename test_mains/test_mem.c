#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "libft.h"

void	prarr(int a[], int l)
{
	int	i = -1;

	printf ("|");
	while (++i < l)
	{
		if (i != l - 1)
			printf ("%i ", a[i]);
		else
			printf ("%i|", a[i]);
	}
}

void	mkarr(int *arr, char *s)
{
	int	i = 0;
	short	sign = 1;

	while (*s)
	{
		if (*s == '-')
			sign = -1;
		else
		{
			*(arr + i) = (*s - '0') * sign;
			sign = 1;
			i++;
		}
		s++;
	}
}

int	main(int ac, char *av[])
{
	(void) ac;

	char	sb[30] = "abcde"; char *s = sb;
	char	ssb[30] = "abcde"; char *ss = ssb;
	char	s1b[30] = "xxxxxxxxxx"; char *s1 = s1b;
	char	s2b[30] = "xxxxxxxxxx"; char *s2 = s2b;
	int		sl = 6;
	int		ab[30] = {1, 2, -3, 4, -5, 9, 0}; int *a = ab;
	int		aab[30] = {1, 2, -3, 4, -5, 9, 0}; int *aa = aab;
	int		a1b[30] = {9, 9, 9, 9, 9, 9}; int *a1 = a1b;
	int		a2b[30] = {9, 9, 9, 9, 9, 9}; int *a2 = a2b;
	int		al = 5;

	if (*av[1] == 'b')
	{
	}

	else if (*(av[1] + 4) == 'e')
	{
	}

	else if (*(av[1] + 4) == 'p')
	{
		printf("string\no:\n|%s|\n", (char *) memcpy(s1, s, sl));
		printf("|%s|\n", s1);
		printf("c:\n|%s|\n", (char *) ft_memcpy(s2, s, sl));
		printf("|%s|\n\nint\no:\n", s2);
		prarr(memcpy(a1, a, al * sizeof(int)), al);
		printf("\n");
		prarr(a1, al);
		printf("\nc:\n");
		prarr(ft_memcpy(a2, a, al * sizeof(int)), al);
		printf("\n");
		prarr(a2, al);
		printf("\n");
	}

	else if (*(av[1] + 4) == 'o')
	{
		if (ac < 3)
		{
			printf ("please provide overlap argument ('o' or 'n')\n");
			return (0);
		}
		if (*av[2] == 'n')
		{
			printf("	---no overlap---\n");
		}
		if (*av[2] == 'o')
		{
			if (ac < 4)
			{
				printf("please provide direction argument ('l' or 'r')\n");
				return (0);
			}
			if (*av[3] == 'l')
			{
				s1 = (s + 2);
				s2 = (ss + 2);
				a1 = (a + 2);
				a2 = (aa + 2);
				printf("	---overlap, dir left---\n");
			}
			if (*av[3] == 'r')
			{
				strcpy(s, ">>abcde");
				strcpy(ss, ">>abcde");
				s1 = s;
				s2 = ss;
				s += 2;
				ss += 2;
				int	tempa[] = {9, 9, 1, 2, -3, 4, -5, 9, 0}; a = tempa;
				int	tempaa[] = {9, 9, 1, 2, -3, 4, -5, 9, 0}; aa = tempaa;
				a1 = a;
				a2 = aa;
				a += 2;
				aa += 2;
				printf("	---overlap, dir right---\n");
			}
		}
		printf(" string\no:\n|%s|\n", (char *) memmove(s1, s, sl));
			printf("|%s|\n", s1);
			printf("c:\n|%s|\n", (char *) ft_memmove(s2, ss, sl));
			printf("|%s|\n\n int\no:\n", s2);
			prarr(memmove(a1, a, al * sizeof(int)), al);
			printf("\n");
			prarr(a1, al);
			printf("\nc:\n");
			prarr(ft_memmove(a2, aa, al * sizeof(int)), al);
			printf("\n");
			prarr(a2, al);
			printf("\n");
	}

	else if (*(av[1] + 4) == 'h')
	{
		if (ac == 2)
		{
			printf("running default test. provide a string, a character and a number for a custom test (char only)\n");
			printf("	string:\no |%s|\n", memchr((const void *) s, 'd', 4));
			printf("c |%s|\n", ft_memchr((const void *) s, 'd', 4));
			printf("	int:\no ");
			prarr(memchr((const void *) a, -5, 8 * sizeof(int)), 3);
			printf("\nc ");
			prarr(ft_memchr((const void *) a, -5, 8 * sizeof(int)), 3);
			printf("\n");
		}
		else if (ac == 5)
		{
			printf("o |%s|\n", memchr((const void *) av[2], (int) *av[3], (size_t) atoi(av[4])));
			printf("c |%s|\n", ft_memchr((const void *) av[2], (int) *av[3], (size_t) atoi(av[4])));
		}
		else
			printf("please provide a string, a character and a number for a custom test.\n");
	}

	else if (*(av[1] + 4) == 'm')
	{
		if (ac != 6)
		{
			printf("please provide the following arguments:\n'char' or 'int'\nTWO arguments to compare and\nhow many elements to compare\nthank you!\n");
			return (0);
		}
		if (*av[2] == 'c')
		{
			printf("o |%i|\n", memcmp((const void*) av[3], (const void *) av[4], (size_t) atoi(av[5])));
			printf("c |%i|\n", ft_memcmp((const void*) av[3], (const void *) av[4], (size_t) atoi(av[5])));
		}
		else if (*av[2] == 'i')
		{
			mkarr(a1, av[3]);
			mkarr(a2, av[4]);
			printf("o |%i|\n", memcmp((const void *) a1, (const void *) a2, atoi(av[5]) * sizeof(int)));
			printf("c |%i|\n", ft_memcmp((const void *) a1, (const void *) a2, atoi(av[5]) * sizeof(int)));
		}
	}
}
