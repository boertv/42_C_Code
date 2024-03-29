/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:30 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 19:50:06 by bvercaem         ###   ########.fr       */
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
	pthread_mutex_t	watch_lock;
	int				watch;
	pthread_mutex_t	state_lock;
	int				game_state;
	void			*philos;
	pthread_t		reaper;
	pthread_mutex_t	*forks;
	int				total;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_target;
	pthread_mutex_t	target_lock;
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
void	ph_lock_and_print(t_philosopher *guts, int *watch, char *msg);
int		grab_forks(t_philosopher *guts);
int		eat(t_philosopher *guts);
void	*reaper(void *input);
void	ft_msleep(int ms);
int		read_watch(t_philo *data);
int		get_ms(struct timeval *a, struct timeval *b);
void	ph_flush(t_philo *data);
void	clear_philo(t_philo *data, int i);
void	clear_forks(t_philo *data, int i);
int		ph_perror(char *item, char *msg);
int		ph_lock_and_check(int *var, pthread_mutex_t *lock);

#endif
