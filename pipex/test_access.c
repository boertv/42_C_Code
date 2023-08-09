#include "pipex.h"

int	main(void)
{
	char	*cmd = "";
	int		check;

	check = access(cmd, X_OK);
	printf("output for %s = %i\n", cmd, check);
	if (check == -1)
	{
		if (!cmd)
			cmd = "(null)";
		perror(cmd);
		return (127);
	}
	printf("ja lap da werkt eh\n");
	return (0);
}
