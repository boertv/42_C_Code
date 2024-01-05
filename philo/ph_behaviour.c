/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_behaviour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:07 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/05 19:51:33 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// returns 1 if eat_target has been reached for all
static int	ma_spagget(t_philosopher *guts)
{
	int	temp;

	temp = guts->data->watch;
	printf("%i %i is eating\n", temp, guts->id);
	guts->last_meal = temp;
	guts->meal_count++;
	if (guts->meal_count == guts->data->eat_target)
	{
		pthread_mutex_lock(&guts->data->lock);
		guts->data->target_hits++;
		pthread_mutex_unlock(&guts->data->lock);
		if (guts->data->target_hits == guts->data->total)
		{
			guts->data->game_state = 2;
			return (1);
		}
	}
	usleep(guts->data->time_to_eat * 1000);
	if (guts->id == 1)
		temp = guts->data->total - 1;
	else
		temp = guts->id - 2;
	pthread_mutex_unlock(guts->data->forks + temp);
	pthread_mutex_unlock(guts->data->forks + (guts->id - 1));
	return (0);
}

static int	grab_forks(t_philosopher *guts)
{
	int	left_fork;

	if (guts->id == 1)
		left_fork = guts->data->total - 1;
	else
		left_fork = guts->id - 2;
	if (pthread_mutex_lock(guts->data->forks + left_fork))
	{
		printf("couldn't lock in fork %i\n", left_fork + 1);
		return (1);
	}
	if (guts->data->game_state)
		return (1);
	printf("%i %i has taken a fork\n", guts->data->watch, guts->id);
	if (pthread_mutex_lock(guts->data->forks + (guts->id - 1)))
	{
		printf("couldn't lock in fork %i\n", guts->id);
		pthread_mutex_unlock(guts->data->forks + left_fork);
		return (1);
	}
	if (guts->data->game_state)
		return (1);
	printf("%i %i has taken a fork\n", guts->data->watch, guts->id);
	return (0);
}

void	*behaviour(void *input)
{
	t_philosopher	*guts;

	guts = input;
	guts->meal_count = 0;
	guts->last_meal = 0;
	usleep(100);
	while (!guts->data->game_state)
	{
		printf("%i %i is thinking\n", guts->data->watch, guts->id);
		if (grab_forks(guts))
			return (NULL);
		if (ma_spagget(guts))
			return (NULL);
		if (guts->data->game_state)
			return (NULL);
		printf("%i %i is sleeping\n", guts->data->watch, guts->id);
		usleep(guts->data->time_to_sleep * 1000);
	}
	return (NULL);
}
