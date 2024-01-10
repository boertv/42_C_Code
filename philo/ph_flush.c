/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_flush.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:39:11 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 19:59:58 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// clears data->philos in reverse starting with i - 1
// sets ptr to NULL
void	clear_philo(t_philo *data, int i)
{
	if (!data->philos)
		return ;
	while (i--)
		pthread_join(((t_philosopher *) data->philos)[i].thread, NULL);
	free(data->philos);
	data->philos = NULL;
}

// clears data->forks in reverse starting with i - 1
// sets ptr to NULL
void	clear_forks(t_philo *data, int i)
{
	if (!data->forks)
		return ;
	while (i--)
		pthread_mutex_destroy(data->forks + i);
	free(data->forks);
	data->forks = NULL;
}

void	ph_flush(t_philo *data)
{
	pthread_mutex_lock(&data->state_lock);
	if (!data->game_state)
		data->game_state = 1;
	pthread_mutex_unlock(&data->state_lock);
	clear_philo(data, data->total);
	clear_forks(data, data->total);
	pthread_mutex_destroy(&data->target_lock);
	pthread_mutex_destroy(&data->watch_lock);
	pthread_mutex_destroy(&data->state_lock);
}
