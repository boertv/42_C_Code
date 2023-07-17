#include "pipex.h"

static int	temp_return(char *s, char **a, int r)
{
	int	i;

	if (s)
		free(s);
	//ft_clear_da()
	if (a)
	{
		i = 0;
		while (a[i])
		{
			free(a[i]);
			i++;
		}
		free(a);
	}
	return (r);
}

int	main(int ac, char *av[])
{
	char	*cmd;
	char	**arg;

	if (ac < 2)
		return (1);
	arg = ft_split(av[1], ' ');
	if (!arg)
		return (1);
	cmd = ft_strjoin("/bin/", arg[0]);
	if (!cmd)
		return (1);
	if (access(cmd, X_OK) == -1)
	{
		perror("access failed");
		return (temp_return(cmd, arg, 127));
	}
	execve(cmd, arg, NULL)
	printf("I Can See You (tv)\n");
	return (temp_return(cmd, arg, 126));
}
