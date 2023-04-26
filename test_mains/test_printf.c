#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
//	printf("\n%i\n", ft_printf("1234567890"));

	char	c = 'c';
	printf("%3c   %-3c  %%\n", c, c);
	ft_printf("%3c  %-3c  %%", c, c);
	printf("\nfin\n");
/*
	char	*s = "test";
	printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	ft_printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	printf("\nfin");
*/
	int	i = 42;
	int	j = -2147483648;
	printf("\n--- |%10i|   |%-10i|   |%6i| ---\n", i, i, j);
	ft_printf("--- |%10i|   |%-10i|   |%6i| ---\n", i, i, j);
	printf("fin\n");
/*
	int		a = 42;
	void	*p = &a;
	printf("---\na:%10p\nb:%-10p\nc:%10p\n---\n", p, p, p);
	ft_printf("---\na:%10p\nb:%-10p\nc:%10p\n---\n", p, p, p);
	printf("\nfin");
*/
}
