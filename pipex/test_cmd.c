#include "pipex.h"

static int	temp_return(char **a, int r)
{
	int	i;

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
	free (arg[0]);
	arg[0] = cmd;
	if (!arg[0])
		return (1);
	if (access(arg[0], X_OK) == -1)
	{
		perror("access failed");
		return (temp_return(arg, 127));
	}
	execve(arg[0], arg, NULL);
	perror(arg[0]);
	return (temp_return(arg, 126));
}
