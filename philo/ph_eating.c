/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eating.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:28:57 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 19:52:42 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	drop_forks(t_philosopher *guts)
{
	int	left_fork;

	if (guts->id == 1)
		left_fork = guts->data->total - 1;
	else
		left_fork = guts->id - 2;
	pthread_mutex_unlock(guts->data->forks + left_fork);
	pthread_mutex_unlock(guts->data->forks + (guts->id - 1));
	if (ph_lock_and_check(&guts->data->game_state, &guts->data->state_lock))
		return (1);
	return (0);
}

// returns 1 if eat_target has been reached for all, or game_state != 0
int	eat(t_philosopher *guts)
{
	int	temp;

	pthread_mutex_lock(&guts->data->watch_lock);
	temp = guts->data->watch;
	pthread_mutex_unlock(&guts->data->watch_lock);
	guts->last_meal = temp;
	ph_lock_and_print(guts, &temp, "is eating");
	guts->meal_count++;
	ft_msleep(guts->data->time_to_eat);
	if (ph_lock_and_check(&guts->data->game_state, &guts->data->state_lock))
		return (drop_forks(guts));
	if (guts->meal_count == guts->data->eat_target)
	{
		pthread_mutex_lock(&guts->data->target_lock);
		guts->data->target_hits++;
		pthread_mutex_unlock(&guts->data->target_lock);
		if (guts->data->target_hits >= guts->data->total)
		{
			pthread_mutex_lock(&guts->data->state_lock);
			guts->data->game_state = 2;
			pthread_mutex_unlock(&guts->data->state_lock);
		}
	}
	return (drop_forks(guts));
}

// not really a strat anymore, just returns left [0] and right [1] fork
static void	fork_strategy(t_philosopher *guts, int *forks)
{
	if (guts->id == 1)
		forks[0] = guts->data->total - 1;
	else
		forks[0] = guts->id - 2;
	forks[1] = guts->id - 1;
}

static int	grab_fork(t_philosopher *guts,
	pthread_mutex_t *grab, pthread_mutex_t *holding)
{
	if (pthread_mutex_lock(grab))
	{
		pthread_mutex_lock(&guts->data->state_lock);
		guts->data->game_state = 4;
		pthread_mutex_unlock(&guts->data->state_lock);
		printf("%i couldn't lock in a fork\n", guts->id);
		if (holding)
			pthread_mutex_unlock(holding);
		return (1);
	}
	if (ph_lock_and_check(&guts->data->game_state, &guts->data->state_lock))
	{
		pthread_mutex_unlock(grab);
		if (holding)
			pthread_mutex_unlock(holding);
		return (1);
	}
	ph_lock_and_print(guts, NULL, "has taken a fork");
	return (0);
}

int	grab_forks(t_philosopher *guts)
{
	int	forks[2];

	fork_strategy(guts, forks);
	if (grab_fork(guts, guts->data->forks + forks[0], NULL))
		return (1);
	if (guts->data->total == 1)
	{
		pthread_mutex_unlock(guts->data->forks + forks[0]);
		pthread_mutex_lock(&guts->data->watch_lock);
		printf("%i %i can't find another fork!\n", guts->data->watch, guts->id);
		pthread_mutex_unlock(&guts->data->watch_lock);
		ft_msleep(guts->data->time_to_die);
		return (1);
	}
	if (grab_fork(guts, guts->data->forks + forks[1],
			guts->data->forks + forks[0]))
		return (1);
	return (0);
}

// DEPRECATED
// returns forks[0]: first_fork and forks[1]: second_fork
// static void	fork_strategy(t_philosopher *guts, int *forks)
// {
// 	if (guts->id % 2)
// 	{
// 		if (guts->id == 1)
// 			forks[0] = guts->data->total - 1;
// 		else
// 			forks[0] = guts->id - 2;
// 		forks[1] = guts->id - 1;
// 	}
// 	else
// 	{
// 		forks[0] = guts->id - 1;
// 		if (guts->id == 1)
// 			forks[1] = guts->data->total - 1;
// 		else
// 			forks[1] = guts->id - 2;
// 	}
// }
