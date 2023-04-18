#include "libft.h"
#include <stdio.h>

// a MESS

t_list	**mklst(int l, char *val[])
{
	t_list	**list;
	t_list	**begin;
	int		i;

	list = (t_list **) malloc(sizeof(t_list *));
	*list = (t_list *) malloc(sizeof(t_list));
	begin = list;
	i = 0;
	while (i < l - 1)
	{
		(*list)->content = val[i];
		(*list)->next = (t_list *) malloc(sizeof(t_list));
		list = &((*list)->next);
		i++;
	}
	(*list)->content = val[i];
	(*list)->next = NULL;

	printf("printing starting list:\n");
	printlst(begin);

	return (begin);
}

void	freelst(t_list **begin)
{
	t_list	*temp;
	t_list	*t;

	if (!begin || !*begin)
		return ;
	t = *begin;
	while (t->next)
	{
		temp = t;
		t = t->next;
		free(temp);
	}
	free(t);
	free(begin);
}

void	printlst(t_list **begin)
{
	if (!begin || !*begin)
	{
		printf("(null)\n");
		return ;
	}
	while ((*begin)->next)
	{
		printf("|%s|  ", (char *) (*begin)->content);
		begin = &((*begin)->next);
	}
	printf("|%s|\n", (char *) (*begin)->content);
}

/*----------MAIN IS HERE----------*/
int	main(int ac, char *av[])
{
	if (ac < 2)
		return (0);
	t_list	**begin = NULL;
	t_list	*list = NULL;

	if (!ft_strncmp(av[1], "lstnew", 7))
	{
		printf("printing starting list\n");
		printlst(begin);
		list = ft_lstnew(av[2]);
		begin = &list;
	}
	else if (!ft_strncmp(av[1], "lstadd_front", 13))
	{
		begin = mklst(ac - 3, av + 3);
		ft_lstadd_front(begin, ft_lstnew(av[2]));
	}
	else if (!ft_strncmp(av[1], "lstsize", 8))
	{
		begin = mklst(ac - 2, av + 2);
		printf("size is: %i\n", ft_lstsize(*begin));
	}
	else if (!ft_strncmp(av[1], "lstlast", 8))
	{
		begin = mklst(ac - 2, av + 2);
		printf("the last element is:\n");
		list = ft_lstlast(*begin);
		printlst(&list);
	}
	else if (!ft_strncmp(av[1], "lstadd_back", 12))
	{
		begin = mklst(ac - 3, av + 3);
		ft_lstadd_back(begin, ft_lstnew(av[2]));
	}
	else if (!ft_strncmp(av[1], "lstdelone", 12))
	{
		begin = mklst(ac - 2, av + 2);
		//delone
	}
	else if (!ft_strncmp(av[1], "lstclear", 12))
	{
		begin = mklst(ac - 2, av + 2);
		//clear
	}
	else if (!ft_strncmp(av[1], "lstiter", 8))
	{
		begin = mklst(ac - 2, av + 2);
		//iter
	}
	else if (!ft_strncmp(av[1], "lstmap", 7))
	{
		begin = mklst(ac - 2, av + 2);
		//map
	}
	printf("printing final list:\n");
	printlst(begin);
	printf("freeing list..\n");
	if (ft_strncmp(av[1], "lstnew", 7))
		freelst(begin);
	else
		free(list);
}
