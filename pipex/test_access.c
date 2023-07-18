#include "pipex.h"

int	main(void)
{
	char	*cmd = "a";

	if (access(cmd, X_OK) == -1)
	{
		perror(cmd);
		return (127);
	}
	printf("ja lap da werkt eh\n");
	return (0);
}
