/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:30 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/08 16:48:16 by bvercaem         ###   ########.fr       */
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
	int				watch;
	char			game_state;
	void			*philos;
	pthread_t		reaper;
	pthread_mutex_t	*forks;
	int				total;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_target;
	pthread_mutex_t	lock;
	int				target_hits;
	char			*err_msg;
}					t_philo;

typedef struct s_philosopher
{
	int			id;
	int			last_meal;
	int			meal_count;
	pthread_t	thread;
	t_philo		*data;
}				t_philosopher;

int		ph_atoi_call(t_philo *data, char *str);
int		assemble(t_philo *data);
void	*behaviour(void *input);
void	*reaper(void *input);
void	ph_flush(t_philo *data);
void	clear_philo(t_philo *data, int i);
void	clear_forks(t_philo *data, int i);
int		ph_perror(char *item, char *msg);

#endif
