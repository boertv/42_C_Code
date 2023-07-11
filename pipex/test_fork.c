#include "pipex.h"

int	main(void)
{
	pid_t	pid;
	char	**arg;

	arg = malloc(sizeof(char *) * 2);
	arg[0] = "-ls";
	arg[1] = NULL;
	pid = fork();
	if (pid == 0) // AM CHILD
	{
		execve("/bin/ls", arg, NULL);
	}
	else // AM PARENT
	{
		pid = wait(&pid);
		if (pid == -1)
		{
			printf("SOMETHING WENT WRONG !!\n");
			exit(EXIT_FAILURE);
		}
		printf("child should have done the thing\n");
	}
}
