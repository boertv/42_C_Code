/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:50:27 by bvercaem          #+#    #+#             */
/*   Updated: 2024/01/11 15:03:47 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_pre_check(t_philo *data, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			data->err_msg = "bad input value";
			return (1);
		}
		if (i == 2147483647)
		{
			data->err_msg = "overflow from input value";
			return (1);
		}
		i++;
	}
	if (i > 10)
	{
		data->err_msg = "overflow from input value";
		return (1);
	}
	return (0);
}

static int	ph_atoi(t_philo *data, char *str)
{
	unsigned int	res;

	while (*str == '+')
		str++;
	res = 0;
	if (ph_pre_check(data, str))
		return (-1);
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > 2147483647)
	{
		data->err_msg = "overflow from input value";
		return (-1);
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
		data->err_msg = "empty argument";
		ph_perror(NULL, "empty argument");
		return (-1);
	}
	res = ph_atoi(data, str);
	if (res == -1)
		ph_perror(str, data->err_msg);
	return (res);
}
