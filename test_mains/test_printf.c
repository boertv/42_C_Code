#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
/*
	char	c = 'c';
	printf("---\na: %3c\nb: %-3c\nc: %3c\n---\n", c, c, c);
	ft_printf("|---\na: %3c\nb: %-3c\nc: %3c\n---|", c, c, c);
	printf("\nfin");
*/
	char	*s = "test";
	printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	ft_printf("---\na:%6s\nb:%-6s\nc:%6s\n---\n", s, s, s);
	printf("\nfin");
}
