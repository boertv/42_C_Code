#include <stdio.h>

int main(void)
{
		/*		fw, -, 0, ., ' ', +, #		*/

	// printf("    |% s| \n", "abc");

	// char    c = 'c';
	// printf(" |%03c| \n", 'c');
	// printf("abc |%-20c| def\n", c);
	// ' ' & '+' & '#' & '0' & '.' all undefined
	// '-' works

	// printf("	|%-05%|  |%#%|\n");
	// printf("	|%-5%| |%5%|\n");
	// ' ' & '+' & '#' don't do nothing but will compile
	// '.' fully ignored, doesn't influence '0'
	// '0' works but ignored when '-' is present
	// '-' works

	// char *s = "abc";
	// printf("|%s| 6.1:|%6.1s| -6.1s:|%-6.1s| #s:|%#s|\n", s, s, s, s);
	// s = NULL;
	// printf("|%s| .1:|%.1s|\n", s, s);
	// NULL will print "(null)" (depending on precision still)
	// works: '.' '-'
	// undefined: ' ' '+' '0' '#'

	printf("  |%.4i|  |%04i|  |%i|\n", -42, 42, 42);
	// works: deja tous
	// special: '0' ignored when '.' present
	// undefined: '#'

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
