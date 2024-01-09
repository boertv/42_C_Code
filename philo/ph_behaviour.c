/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_behaviour.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:51:07 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/09 15:13:20 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// returns 1 if eat_target has been reached for all, or game_state
static int	ma_spagget(t_philosopher *guts)
{
	int	temp;

	temp = guts->data->watch;
	printf("%i %i is eating\n", temp, guts->id);
	guts->last_meal = temp;
	guts->meal_count++;
	usleep(guts->data->time_to_eat * 1000);
	if (guts->data->game_state)
		return (1);
	if (guts->meal_count == guts->data->eat_target)
	{
		pthread_mutex_lock(&guts->data->lock);
		guts->data->target_hits++;
		pthread_mutex_unlock(&guts->data->lock);
		if (guts->data->target_hits >= guts->data->total)
		{
			guts->data->game_state = 2;
			return (1);
		}
	}
	return (0);
}

static int	drop_forks(t_philosopher *guts)
{
	int	left_fork;

	if (guts->id == 1)
		left_fork = guts->data->total - 1;
	else
		left_fork = guts->id - 2;
	pthread_mutex_unlock(guts->data->forks + left_fork);
	pthread_mutex_unlock(guts->data->forks + (guts->id - 1));
	if (guts->data->game_state)
		return (1);
	return (0);
}

// returns forks[0]: first_fork and forks[1]: second_fork
static void	fork_strategy(t_philosopher *guts, int *forks)
{
	if (guts->id % 2)
	{
		if (guts->id == 1)
			forks[0] = guts->data->total - 1;
		else
			forks[0] = guts->id - 2;
		forks[1] = guts->id - 1;
	}
	else
	{
		forks[0] = guts->id - 1;
		if (guts->id == 1)
			forks[1] = guts->data->total - 1;
		else
			forks[1] = guts->id - 2;
	}
}

static int	grab_forks(t_philosopher *guts)
{
	int	forks[2];

	fork_strategy(guts, forks);
	if (pthread_mutex_lock(guts->data->forks + forks[0]))
	{
		guts->data->game_state = 4;
		printf("couldn't lock in fork %i\n", forks[0] + 1);
		return (1);
	}
	if (guts->data->game_state)
	{
		pthread_mutex_unlock(guts->data->forks + forks[0]);
		return (1);
	}
	printf("%i %i has taken a fork\n", guts->data->watch, guts->id);
	if (guts->data->total == 1)
	{
		printf("%i %i can't find another fork!\n", guts->data->watch, guts->id);
		pthread_mutex_unlock(guts->data->forks + forks[0]);
		usleep(guts->data->time_to_die * 1000);
		return (1);
	}
	if (pthread_mutex_lock(guts->data->forks + forks[1]))
	{
		guts->data->game_state = 4;
		printf("couldn't lock in fork %i\n", forks[1] + 1);
		pthread_mutex_unlock(guts->data->forks + forks[0]);
		return (1);
	}
	if (guts->data->game_state)
	{
		drop_forks(guts);
		return (1);
	}
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
		ma_spagget(guts);
		if (drop_forks(guts))
			return (NULL);
		printf("%i %i is sleeping\n", guts->data->watch, guts->id);
		usleep(guts->data->time_to_sleep * 1000);
	}
	return (NULL);
}
