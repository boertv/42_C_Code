/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:03:46 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 19:40:57 by bvercaem         ###   ########.fr       */
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
		pthread_mutex_unlock(&data->watch_lock);
		i++;
		if (fast >= data->time_to_die)
		{
			pthread_mutex_lock(&data->state_lock);
			data->game_state = 1;
			pthread_mutex_lock(&data->watch_lock);
			printf("%i %i died\n", data->watch, i);
			pthread_mutex_unlock(&data->watch_lock);
			pthread_mutex_unlock(&data->state_lock);
			return (NULL);
		}
	}
	return (NULL);
}

// error: prints
void	*reaper(void *input)
{
	t_philo		*data;
	static int	i = 0;

	data = input;
	while (!ph_lock_and_check(&data->game_state, &data->state_lock))
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
