#include <stdio.h>
//#include <unistd.h>

int main(void)
{
	int	i = -3;
	unsigned int	j = -3;
	printf("   |%012x| \n", i);
	printf("   |%0#12x| \n", j);
	printf("   |%#14.10x| \n\n", i);

	printf("   |%6.3i| \n", i);
	printf("   |%06.i| \n", i);
	printf("%i\n\n", printf("   hallo?|%.2147483647i| \n\n", i));

	printf("   |%6i| \n", i);
/*
	char    c = 'c';
	printf("abc |%c| def\n", c);
	printf("abc |%-20c| def\n", c);
*//*
	char *s = "abc";
	printf("xx |%5s| zz\n", s);
*//*
	int		a = 42;
	void	*p = &a;
	write(0, &p, 16);
	printf("--|%-16p|--\n", p);
*/
}
