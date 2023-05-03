#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int a = 42;
	void *p = &a;
	int i = printf("\t|%-20p|\n", p);
	int j = ft_printf("\t|%-20p|\n", p);
	ft_printf("  ori = %i / cpy = %i\n", i, j);
}
