/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:30 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/04 18:04:24 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	struct timeval	start_time;
	struct timeval	temp_time;
	char			game_state;
	int				total;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_target;
	char			*err_msg;
}					t_philo;

typedef struct s_philosopher
{
	int		id;
	int		timer;
	int		meal_count;
	t_philo	*data;
}		t_philosopher;

int				ph_atoi_call(t_philo *data, char *str);
int				assemble(t_philo *data);
t_philosopher	*behaviour(t_philosopher *guts);
void			ph_flush(t_philo *data);
void			clear_philo(t_philo *data, int i);
void			clear_forks(t_philo *data, int i);

#endif
