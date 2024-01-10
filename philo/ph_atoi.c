/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:50:27 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/10 18:08:09 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(t_philo *data, char *str)
{
	unsigned int	res;

	while (*str == '+')
		str++;
	res = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			data->err_msg = "bad input value";
			return (-1);
		}
		res = (res * 10) + (*str - '0');
		if (res > 2147483647)
		{
			data->err_msg = "overflow from input value";
			return (-1);
		}
		str++;
	}
	return (res);
}

// error -1: prints msg
// just returns -1 if data->err_msg is already set
int	ph_atoi_call(t_philo *data, char *str)
{
	int	res;

	if (data->err_msg)
		return (-1);
	if (!str || !*str)
	{
		ph_perror(NULL, "empty argument");
		return (-1);
	}
	res = ph_atoi(data, str);
	if (res == -1)
		ph_perror(str, data->err_msg);
	return (res);
}
