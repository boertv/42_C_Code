#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	int a = 0;
//	void *p = &a;
	int i = printf("|% i|\n", a);
	int j = ft_printf("|% i|\n", a);
	ft_printf("%% i  ori = %i / cpy = %i\n", i, j);
	i = printf("|% .3i|\n", a);
	j = ft_printf("|% .3i|\n", a);
	ft_printf("%% .3i  ori = %i / cpy = %i\n", i, j);
	i = printf("|% 5.3i|\n", a);
	j = ft_printf("|% 5.3i|\n", a);
	ft_printf("%% 5.3i  ori = %i / cpy = %i\n", i, j);
}
