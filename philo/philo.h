/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:21:30 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/03 18:09:59 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_philo
{
	int	game_state;
	int	time_to_eat;
	int	time_to_sleep;
}		t_philo;

typedef struct s_philosopher
{
	int	timer;
	int	state;
	int	time_to_die;
}

#endif