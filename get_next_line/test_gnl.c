#include "get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <strings.h>

int	main(int ac, char *av[])
{
	if (ac < 2)
		return (0);

/*################################################################################*/
/*# test die door een bestand gaat en het dan sluit voor het volgende te openen. #*/
/*################################################################################*/

	// int	n = 0;
	// while (av[++n])
	// {
	// 	int fd = open(av[n], O_RDONLY);
	// 	write(1, "\n\t\t\t  {", 7);
	// 	write(1, av[n], strlen(av[n]));
	// 	char *output = "blablablablablablablablablablablablablablablablabla";

	// 	printf("}\n\t\t\t-----fd = |%i|-----\n", fd);
	// 	while (output)
	// 	{
	// 		output = get_next_line(fd);
	// 		printf(">>>>> |%s| <<<<<\n", output);
	// 		if (output)
	// 			free(output);
	// 	}
	// 	printf("\n\tFIN\n\n");
	// 	close (fd);
	// }


/*###############################################################################*/
/*# test die effectief verschillende bestanden tegelijk opvraagt. lijn per lijn #*/
/*###############################################################################*/

	int n = 1;
	char *print;
	while (av[n])
		n++;
	int fd[n];
	int i = n - 1;
	int j = n;
	while (n-- > 1)
	{
		fd[n] = open(av[n], O_RDONLY);
	}
	while (i)
	{
		n = j;
		while (n-- > 1)
		{
			if (fd[n] != -1)
			{
				write (1, "\n\t\t{", 4);
				write (1, av[n], strlen(av[n]));
				printf("} [%i]\n", fd[n]);
				print = get_next_line(fd[n]);
				printf(">>>|%s|<<<\n", print);
				if (!print)
				{
					close(fd[n]);
					fd[n] = -1;
					i--;
				}
				else
					free(print);
			}
		}
	}

	printf("\n\n\n");
	system("Leaks a.out");
}
