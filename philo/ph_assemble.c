/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_assemble.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:52:06 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/05 15:39:45 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_philo(t_philo *data, int id)
{
	t_philosopher	*guts;

	guts = ((t_philosopher *) data->philos) + (id - 1);
	guts->id = id;
	guts->data = data;
	if (pthread_create(&guts->thread, NULL, behaviour, guts))
	{
		clear_philo(data, id - 1);
		data->err_msg = "could not assemble all philosophers";
		return (1);
	}
	return (0);
}

static int	create_forks(t_philo *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->total);
	if (!data->forks)
	{
		data->err_msg = "not enough available memory";
		return (1);
	}
	i = 0;
	while (++i <= data->total)
	{
		if (pthread_mutex_init(data->forks + (i - 1), NULL))
		{
			clear_forks(data, i - 1);
			data->err_msg = "could not create all forks";
			return (1);
		}
	}
	return (0);
}

// error 1: sets err_msg, doesn't print
int	assemble(t_philo *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philosopher) * data->total);
	if (!data->philos)
	{
		data->err_msg = "not enough available memory";
		return (1);
	}
	if (create_forks(data))
		return (1);
	i = 0;
	while (++i <= data->total)
	{
		if (create_philo(data, i))
			return (1);
	}
	if (pthread_create(&data->reaper, NULL, reaper, data))
	{
		data->err_msg = "reaper could not be summoned";
		return (1);
	}
	return (0);
}
