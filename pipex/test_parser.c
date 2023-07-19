#include "pipex.h"
#include <stdio.h>

void	print_ma_shit(char **da)
{
	int	i;

	if (!da)
		return ;
	i = 0;
	printf(" {");
	while (da[i])
	{
		printf("%s", da[i]);
		if (da[i + 1])
			printf("|");
		i++;
	}
	printf("}\n");
}

int	main(void)
{
	char	*s;
	char	**da;

	s = "abc \" d ' e ' f \" g h i 'jkl \"'";
	da = ft_split(s, ' ');
	print_ma_shit(da);
	printf("r = %i\n", px_parser(da));
	print_ma_shit(da);
	ft_clear_da(da);
	return (0);
}
