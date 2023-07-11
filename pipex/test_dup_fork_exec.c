#include "pipex.h"

//contains forbidden macro i think?
//just write it out tho :)

int	main()
{
	int		fds[2];
	char	**arg;
	pid_t	pid;
	int		stat;

	fds[0] = open("infile.txt", O_RDONLY);
	fds[1] = open("outfile.txt", O_WRONLY);
	arg = malloc(sizeof(char *) * 2);
	arg[0] = "-e";
	arg[1] = NULL;
	pid = fork();
	if (pid == 0)
	{
		sleep(5);
		dup2(fds[0], STDIN_FILENO);
		dup2(fds[1], STDOUT_FILENO);
		execve("/bin/cat", arg, NULL);
	}
	else
	{
		// pid = wait(NULL); //also works
		// if (pid == -1)
		// 	printf("YIKES\n");
		pid = waitpid(pid, &stat, 0);
		if (pid == -1)
			exit(EXIT_FAILURE);
		else
			printf("wait stat = %i\n", WIFEXITED(stat)); //if non-zero, process ended normally
		close(fds[0]);
		close(fds[1]);
		free(arg);
		exit(EXIT_SUCCESS);
	}
}
