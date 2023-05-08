#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i = printf("ori: |%5s|   |%-5s|   |%5.1s|   |%.s|   |%8s|\n", "abc", "abc", "abc", "abc", NULL);
	int j = ft_printf("ori: |%5s|   |%-5s|   |%5.1s|   |%.s|   |%8s|\n", "abc", "abc", "abc", "abc", NULL);
	printf("   %i/%i\n", i, j);
	return (1);
}
