/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:20:21 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 19:55:37 by bvercaem         ###   ########.fr       */
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

int	ph_perror(char *item, char *msg)
{
	if (!msg)
		return (1);
	printf("philo: ");
	if (item)
		printf("%s: ", item);
	printf("%s\n", msg);
	return (1);
}

// error 1: prints msg
static int	ph_init(t_philo *data, char **av)
{
	if (pthread_mutex_init(&data->target_lock, NULL))
		return (ph_perror(NULL, "could not initialise a mutex"));
	if (pthread_mutex_init(&data->watch_lock, NULL))
		return (ph_perror(NULL, "could not initialise a mutex"));
	if (pthread_mutex_init(&data->state_lock, NULL))
		return (ph_perror(NULL, "could not initialise a mutex"));
	data->err_msg = NULL;
	data->philos = NULL;
	data->forks = NULL;
	data->total = ph_atoi_call(data, av[1]);
	data->time_to_die = ph_atoi_call(data, av[2]);
	data->time_to_eat = ph_atoi_call(data, av[3]);
	data->time_to_sleep = ph_atoi_call(data, av[4]);
	data->target_hits = 0;
	if (av[5])
		data->eat_target = ph_atoi_call(data, av[5]);
	else
		data->eat_target = -1;
	if (data->err_msg)
		return (1);
	data->game_state = 0;
	gettimeofday(&data->start_time, NULL);
	data->watch = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	data;

	if (ac != 5 && ac != 6)
		return (ph_perror(NULL, "not enough arguments"));
	if (ph_init(&data, av))
		return (1);
	if (!data.eat_target || !data.total)
		return (0);
	if (assemble(&data))
	{
		ph_flush(&data);
		return (ph_perror(NULL, data.err_msg));
	}
	pthread_join(data.reaper, NULL);
	ph_flush(&data);
	return (0);
}
