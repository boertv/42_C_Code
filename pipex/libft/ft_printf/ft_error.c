/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/24 16:35:57 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// calls va_end, prints given error and returns null.
void	*ft_error_null(const char *error, const char *func, va_list *pva)
{
	if (pva)
		va_end(*pva);
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

// calls va_end, prints given error and returns -1.
short	ft_error_minone(const char *error, const char *func, va_list *pva)
{
	if (pva)
		va_end(*pva);
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
	return (-1);
}
