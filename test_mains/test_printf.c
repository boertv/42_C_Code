#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	ft_printf("char:\n");

	char	c = 'c';
	printf("%3c|  |%-3c|  |%%\n", c, c);
	ft_printf("%3c|  |%-3c|  |%%", c, c);
	printf("\nfin\n\n");

	ft_printf("string:\n");

	char	*s = "test";
	printf("ori:---|%6s|  |%-6s|  |%6s|---\n", s, s, s);
	ft_printf("cpy:---|%6s|  |%-6s|  |%6s|---\n", s, s, s);
	printf("fin\n\n");

	ft_printf("int and decimal:\n");

	int	i = 42;
	int	j = -2147483648;
	int	k = 0;
	printf("ori:--- |%06.4i|   |%04i|   |%.6u| ---\n", i, i, j);
	ft_printf("cpy:--- |%06.4i|   |%04i|   |%.6u| ---\n", i, i, j);
	i = printf("\nori:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	j = ft_printf("cpy:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	ft_printf("ori: %i / cpy: %i\n", i - 1, j);
	printf("fin\n\n");

	ft_printf("hexadecimal:\n");

	int	e = 42;
	int	f = 0;
	printf("ori:--- |%#08x|   |%#8X|   |%-#x| ---\n", e, e, e);
	ft_printf("cpy:--- |%#08x|   |%#8X|   |%-#x| ---\n", e, e, e);
	e = printf("\nori:--- |%x|   |%.x|   |%.0x| ---\n", f, f, f);
	f = ft_printf("cpy:--- |%x|   |%.x|   |%.0x| ---\n", f, f, f);
	ft_printf("ori: %i / cpy: %i\n", e - 1, f);
	printf("fin\n\n");

	ft_printf("pointer:\n");

	int		t = 42;
	void	*p = &t;
	int a = printf("ori:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	int b = ft_printf("cpy:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	ft_printf("ori: %i / cpy: %i\n", a, b);
	ft_printf("fin\n\n");
}
