#include <unistd.h>
#include <stdlib.h>

int	main(int ac, char *av[])
{
	if (ac != 3)
		return (0);
	if (truncate(av[1], atoi(av[2])) < 0)
		write(1, "oops we failed :s\n", 18);
}
