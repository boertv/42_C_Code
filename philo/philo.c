/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:20:21 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/03 14:24:30 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (printf("litteraly wtf are you even doing\n"));
	(void)av;
	return (printf("alright congratulations you can count to five\n"));
}
