#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int a = 0;
//	void *p = &a;
	int i = printf("|%+0i|\n", a);
	int j = ft_printf("|%+0i|\n", a);
	ft_printf("  ori = %i / cpy = %i\n", i, j);
}
