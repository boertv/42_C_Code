#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
	{
		write(1, "please provide a filename and a bytesize\n\n", 42);
		write(1, "other usefull commands:\n\txxd -p [file] = hexdumps the content of a file, '0a' is a newline.\n\tstat [file] = shows stats of a file including size somewhere in the chaos\nhope this helps :3\n", 186);
		return (0);
	}
	if (truncate(av[1], atoi(av[2])) < 0)
	{
		write(1, "oops we failed :s\n", 18);
		return (0);
	}
	return (1);
}
