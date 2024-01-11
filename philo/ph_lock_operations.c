/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_lock_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:37:21 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/11 14:37:38 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// returns *var after retrieving it inside a lock
int	ph_lock_and_check(int *var, pthread_mutex_t *lock)
{
	int	value;

	pthread_mutex_lock(lock);
	value = *var;
	pthread_mutex_unlock(lock);
	return (value);
}

// prints "[watch] [id] [msg]\n"
// doesn't print if (game_state), if (watch) uses that instead of data->watch
void	ph_lock_and_print(t_philosopher *guts, int *watch, char *msg)
{
	pthread_mutex_lock(&guts->data->state_lock);
	if (guts->data->game_state)
	{
		pthread_mutex_unlock(&guts->data->state_lock);
		return ;
	}
	if (!watch)
	{
		pthread_mutex_lock(&guts->data->watch_lock);
		printf("%i %i %s\n", guts->data->watch, guts->id, msg);
		pthread_mutex_unlock(&guts->data->watch_lock);
	}
	else
		printf("%i %i %s\n", *watch, guts->id, msg);
	pthread_mutex_unlock(&guts->data->state_lock);
}
