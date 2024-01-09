/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:03:46 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/09 18:20:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*vibe_check(t_philo *data)
{
	int	fast;
	int	i;

	i = 0;
	while (i < data->total)
	{
		pthread_mutex_lock(&data->watch_lock);
		fast = data->watch - ((t_philosopher *)data->philos)[i].last_meal;
		i++;
		if (fast >= data->time_to_die)
		{
			data->game_state = 1;
			printf("%i %i died\n", data->watch, i);
			pthread_mutex_unlock(&data->watch_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&data->watch_lock);
	}
	return (NULL);
}

// error: prints
void	*reaper(void *input)
{
	t_philo		*data;
	static int	i = 0;

	data = input;
	while (!data->game_state)
	{
		usleep(100);
		i++;
		if (i > 10)
			i = 1;
		pthread_mutex_lock(&data->watch_lock);
		data->watch = read_watch(data);
		pthread_mutex_unlock(&data->watch_lock);
		if (i == 10)
			vibe_check(data);
	}
	return (NULL);
}
