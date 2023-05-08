#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = printf("ori: |%-5%|   |%5%|   |%05%|\n");
	int j = ft_printf("ori: |%-5%|   |%5%|   |%05%|\n");
	printf("   %i/%i\n", i, j);
	return (1);
}
