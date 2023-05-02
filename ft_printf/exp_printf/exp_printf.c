#include <stdio.h>

int main(void)
{
/*
	int	i = -3;
	unsigned int	j = -3;
	printf("   |%012x| \n", i);
	printf("   |%0#12x| \n", j);
	printf("   |%#14.10x| \n\n", i);

	printf("   |%6.3i| \n", i);
	printf("   |%06.i| \n", i);
	printf("%i\n\n", printf("   hallo?|%.2147483647i| \n\n", i));

	printf("   |%6i| \n", i);
*//*
	char    c = 'c';
	printf("abc |%c| def\n", c);
	printf("abc |%-20c| def\n", c);
*/
	char *s = "abc";
	printf("|%s| .1:|%.1s| .s:|%.s|\n", s, s, s);
/*
	int		a = 42;
	void	*p = &a;
	void	*q = NULL;
	printf("--|%20p|  |%-20p|--\n", p, p);
	printf("--|%20p|  |%-20p|--\n", q, q);

	int		pi = (int) p;
	unsigned int pj = (unsigned int) p;
	long	pl = (long) p;
	printf("int: |%x|  unsigned: |%x|  long: |%lx|\n", pi, pj, pl);
*/
}
