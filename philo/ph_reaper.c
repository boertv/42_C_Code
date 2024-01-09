/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_reaper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:03:46 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/08 18:58:18 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// subtracts a from b and returns result in ms, rounds down
static int	get_ms(struct timeval *a, struct timeval *b)
{
	long int	res;
	int			temp;

	res = b->tv_sec - a->tv_sec;
	temp = b->tv_usec - a->tv_usec;
	if (temp < 0)
	{
		res -= 1;
		temp += 1000000;
	}
	res *= 1000;
	temp /= 1000;
	res += temp;
	if (res > 2147483647)
		return (2147483647);
	return ((int) res);
}

static void	*vibe_check(t_philo *data)
{
	int	fast;
	int	i;

	i = 0;
	while (i < data->total)
	{
		fast = data->watch - ((t_philosopher *)data->philos)[i].last_meal;
		i++;
		if (fast >= data->time_to_die)
		{
			data->game_state = 1;
			printf("%i %i died\n", data->watch, i);
			return (NULL);
		}
	}
	return (NULL);
}

// error: prints
void	*reaper(void *input)
{
	t_philo			*data;
	struct timeval	time;

	data = input;
	while (!data->game_state)
	{
		usleep(500);
		if (gettimeofday(&time, NULL))
		{
			ph_perror(NULL, "time of day could not be retrieved");
			data->game_state = 3;
			return (NULL);
		}
		data->watch = get_ms(&data->start_time, &time);
		vibe_check(data);
	}
	return (NULL);
}
