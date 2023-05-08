/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/08 11:54:17 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

// just calls va_end and then returns NULL for moulinette
void	*ft_error_null(const char *error, const char *func, va_list *pva)
{
	if (pva)
		va_end(*pva);
	return (NULL);
	if (func)
	{
		write(1, "\nAn error occured in '", 22);
		write(1, func, ft_strlen(func));
	}
	if (error)
	{
		write(1, "'\nError concerning '", 20);
		write(1, error, ft_strlen(error));
	}
	if (func || error)
		write(1, "'\n", 2);
	return (NULL);
}

// just calls va_end and then returns -1 for moulinette
short	ft_error_minone(const char *error, const char *func, va_list *pva)
{
	if (pva)
		va_end(*pva);
	return (-1);
	if (func)
	{
		write(1, "\nAn error occured in '", 22);
		write(1, func, ft_strlen(func));
	}
	if (error)
	{
		write(1, "' error concerning '", 20);
		write(1, error, ft_strlen(error));
	}
	if (func || error)
		write(1, "'\n", 2);
	return (-1);
}
