#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int	i;
	int	j;
	ft_printf("char:\n");

	char	c = 'c';
	i = printf("ori:---|%3c|  |%-3c|  |%%|\n", c, c);
	j = ft_printf("cpy:---|%3c|  |%-3c|  |%%|\n", c, c);
	ft_printf("ori = %i, cpy = %i\n", i, j);
	ft_printf("test met '%%%%' en niets buiten de specifier:\n|");
	j = ft_printf("%%");
	ft_printf("| = %i\ntest met lege format:\n|", j);
	j = ft_printf("");
	ft_printf("| = %i\ntest met leeg character:\n", j);
	c = '\0';
	i = printf("ori: variabele |%c| litteral |%c|\n", c, '\0');
	j = ft_printf("cpy: variabele |%c| litteral |%c|\n", c, '\0');
	ft_printf("ori = %i, cpy = %i\n", i, j);
	i = printf("ori: |%c| |%4c| |%-4c| \n", '\0', 0, c);
	j = ft_printf("cpy: |%c| |%4c| |%-4c| \n", '\0', 0, c);
	ft_printf("ori = %i, cpy = %i\n", i, j);
	printf("fin\n\n");

	ft_printf("string:\n");

	char	*s = "test";
	ft_printf("vierde test is met fw = INT_MAX\n");
	i = printf("ori:---|%s|  |%-6s|  |%6s|  |%2147483647s|---", s, s, s, s);
	printf("\n");
	j = ft_printf("cpy:---|%s|  |%-6s|  |%6s|  |%2147483647s|---", s, s, s, s);
	ft_printf("\nori = %i, cpy = %i\n", i, j);
	s = "abcd";
	i = printf("|%s| |%.2s| |%-.2s|\n", s, s, s);
	j = ft_printf("|%s| |%.2s| |%-.2s|\n", s, s, s);
	ft_printf("ori = %i, cpy = %i\n", i, j);
	i = printf("|%.s| |%4.2s| |%-4.2s|\n", s, s, s);
	j = ft_printf("|%.s| |%4.2s| |%-4.2s|\n", s, s, s);
	ft_printf("ori = %i, cpy = %i\n", i, j);
	

	s = "";
	ft_printf("\nnou me ne lege string:\n");
	i = printf("|%s| |%4s| |%-4s|\n", s, s, s);
	j = ft_printf("|%s| |%4s| |%-4s|\n", s, s, s);
	ft_printf("ori = %i, cpy = %i\n", i, j);

	ft_printf("\nnu gaan we nen NULL pointer doorgeven:\n");
	s = NULL;
	i = printf("|%s| |%10s| |%-10s|\n", s, s, s);
	j = ft_printf("|%s| |%10s| |%-10s|\n", s, s, s);
	ft_printf("ori = %i, cpy = %i\n", i, j);
	printf("fin\n\n");

	ft_printf("int and decimal:\n");

	i = 42;
	j = -2147483648;
	int	k = 0;
	printf("ori:--- |%06.4i|   |%04i|   |%.6u| ---\n", i, i, j);
	ft_printf("cpy:--- |%06.4i|   |%04i|   |%.6u| ---\n\n", i, i, j);
	i = printf("ori:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	j = ft_printf("cpy:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	ft_printf("ori: %i / cpy: %i\n", i, j);
	printf("fin\n\n");

	ft_printf("hexadecimal:\n");

	int	e = 42;
	int	f = 0;
	i = printf("ori:--- |%#08x|   |%#8X|   |%-#x| ---\n", e, e, e);
	j = ft_printf("cpy:--- |%#08x|   |%#8X|   |%-#x| ---\n", e, e, e);
	ft_printf("ori: %i / cpy: %i\n\n", i, j);
	i = printf("ori:--- |%x|   |%.x|   |%.0x| ---\n", f, f, f);
	j = ft_printf("cpy:--- |%x|   |%.x|   |%.0x| ---\n", f, f, f);
	ft_printf("ori: %i / cpy: %i\n", i, j);
	printf("fin\n\n");

	ft_printf("pointer:\n");

	int		t = 42;
	void	*p = &t;
	i = printf("ori:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	j = ft_printf("cpy:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	ft_printf("ori: %i / cpy: %i\n(void *)-1:\n");
	p = (void *) -1;
	i = printf("ori: %p\n", p);
	j = ft_printf("cpy: %p\n", p);
	ft_printf("ori = %i / cpy = %i\n", i, j);
	ft_printf("\nand now a NULL pointer:\n", i, j);
	p = NULL;
	i = printf("|%p|\n", p);
	j = ft_printf("|%p|\n", p);
	ft_printf("ori: %i / cpy: %i\n", i, j);
	ft_printf("fin\n\n");
}
