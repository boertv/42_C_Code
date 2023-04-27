#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
//	printf("\n%i\n", ft_printf("1234567890"));
/*
	char	c = 'c';
	printf("%3c|  |%-3c|  |%%\n", c, c);
	ft_printf("%3c|  |%-3c|  |%%", c, c);
	printf("\nfin\n\n");
*//*
	char	*s = "test";
	printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	ft_printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	printf("\nfin\n\n");
*//*
	int	i = 42;
	int	j = -2147483648;
	int	k = 0;
	printf("ori:--- |%06.4i|   |%04i|   |%.6u| ---\n", i, i, j);
	ft_printf("cpy:--- |%06.4i|   |%04i|   |%.6u| ---\n", i, i, j);
	i = printf("\nori:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	j = ft_printf("cpy:--- |% d|   |%+.d|   |%.0d| ---\n", k, k, k);
	ft_printf("ori: %i / cpy: %i\n", i - 1, j);
	printf("fin\n\n");
*//*
	int	i = 42;
	int	j = 0;
	printf("ori:--- |%#08x|   |%#8X|   |%-#x| ---\n", i, i, i);
	ft_printf("cpy:--- |%#08x|   |%#8X|   |%-#x| ---\n", i, i, i);
	i = printf("\nori:--- |%x|   |%.x|   |%.0x| ---\n", j, j, j);
	j = ft_printf("cpy:--- |%x|   |%.x|   |%.0x| ---\n", j, j, j);
	ft_printf("ori: %i / cpy: %i\n", i - 1, j);
	printf("fin\n\n");
*/
	int		t = 42;
	void	*p = &t;
	int a = printf("ori:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	int b = ft_printf("cpy:--- |%20p|   |%-20p|   |%p| ---\n", p, p, p);
	ft_printf("ori: %i / cpy: %i\n", a, b);
	printf("fin\n\n");
}
