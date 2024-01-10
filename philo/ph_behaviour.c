/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_behaviour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:07 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 20:17:17 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	*behaviour(void *input)
{
	t_philosopher	*guts;

	guts = input;
	guts->meal_count = 0;
	guts->last_meal = 0;
	ph_lock_and_print(guts, NULL, "is thinking");
	if (!(guts->id % 2))
		ft_msleep(ft_min(guts->data->time_to_eat, guts->data->time_to_die / 2));
	while (!ph_lock_and_check(&guts->data->game_state, &guts->data->state_lock))
	{
		if (grab_forks(guts))
			return (NULL);
		if (eat(guts))
			return (NULL);
		ph_lock_and_print(guts, NULL, "is sleeping");
		if (ph_lock_and_check(&guts->data->game_state, &guts->data->state_lock))
			break ;
		ft_msleep(guts->data->time_to_sleep);
		ph_lock_and_print(guts, NULL, "is thinking");
	}
	return (NULL);
}
