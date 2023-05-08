#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = printf("ori: |%-5c|   |%5c|   |%5c|\n", 'a', 'a', 0);
	int j = ft_printf("ori: |%-5c|   |%5c|   |%5c|\n", 'a', 'a', 0);
	printf("   %i/%i\n", i, j);
	return (1);
}
