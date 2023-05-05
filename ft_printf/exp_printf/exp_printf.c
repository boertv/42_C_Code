#include <stdio.h>

int main(void)
{
		/*		fw, -, 0, ., ' ', +, #		*/
	// int	i = -3;
	// unsigned int	j = -3;
	// printf("    |%012x| \n", i);
	// printf("    |%0#12x| \n", j);
	// printf("    |%-.5i| \n\n", 19);

	// printf("    |%6.3i| \n", i);
	// printf("06.i|%06.i| \n", i);
	// printf("%i\n\n", printf("hoi%i\n   hallo?\n . hiiiiiii\n|%.2147483647i| \n\n", 42, 42));

	// printf("    |%6i| \n", i);

	// char    c = 'c';
	// printf("abc |%c| def\n", c);
	// printf("abc |%-20c| def\n", c);

	// printf("	|%-05%|  |%#%|\n");
	// printf("	|%-5%| |%5%|\n");
	// ' ' & '+' & '#' don't do nothing but will compile
	// '.' fully ignored, doesn't influence '0'
	// '0' works
	// '-' works but if present ignores '0'

	// char *s = "abc";
	// printf("|%s| .1:|%.1s| .s:|%.s| .6:|%.6s|\n", s, s, s, s);
	// s = NULL;
	// printf("|%s| .1:|%.1s|\n", s, s);


	// int		a = 42;
	// void	*p = &a;
	// void	*q = NULL;
	// printf("sizeof(void *) = %lu or %lu\n", sizeof(void *), sizeof(p));
	// printf("sizes: int = %lu long = %lu unsigned = %lu\n", sizeof(int), sizeof(long), sizeof(unsigned));
	// printf("       unsigned long = %lu long long = %lu\n", sizeof(unsigned long), sizeof(long long));
	// p = (void *) -1;
	// long	l = (long) p;
	// unsigned long	u = (unsigned long) p;
	// long	b = (long) u;
	// printf("(void *)-1 = %p long = %#lx uns long = %#lx back to long = %#lx\n", p, l, u, b);

	// printf("\n");
	// printf("--|%20p|  |%-20p|--\n", p, p);
	// printf("--|%20p|  |%-20p|--\n", q, q);
	// printf("--|%10.5p|  |%-10.5p|--\n", p, p);

	// int		pi = (int) p;
	// unsigned int pj = (unsigned int) p;
	// long	pl = (long) p;
	// printf("int: |%x|  unsigned: |%x|  long: |%lx|\n", pi, pj, pl);

}
