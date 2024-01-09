/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_msleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:58:17 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/09 18:52:12 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// subtracts a from b and returns result in ms, rounds down
int	get_ms(struct timeval *a, struct timeval *b)
{
	long int	res;
	int			temp;

	res = b->tv_sec - a->tv_sec;
	temp = b->tv_usec - a->tv_usec;
	if (temp < 0)
	{
		res -= 1;
		temp += 1000000;
	}
	res *= 1000;
	temp /= 1000;
	res += temp;
	if (res > 2147483647)
		return (2147483647);
	return ((int) res);
}

int	read_watch(t_philo *data)
{
	struct timeval	b;

	gettimeofday(&b, NULL);
	return (get_ms(&data->start_time, &b));
}

void	ft_msleep(int ms)
{
	struct timeval	start;
	struct timeval	current;

	if (!ms)
		return ;
	gettimeofday(&start, NULL);
	usleep(100);
	gettimeofday(&current, NULL);
	while (get_ms(&start, &current) < ms)
	{
		usleep(100);
		gettimeofday(&current, NULL);
	}
}
