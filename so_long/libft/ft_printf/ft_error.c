/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:13:40 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/06 17:31:49 by bvercaem         ###   ########.fr       */
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
		write(STDERR_FILENO, "\nAn error occured in '", 22);
		write(STDERR_FILENO, func, ft_strlen(func));
	}
	if (error)
	{
		write(STDERR_FILENO, "'\nError concerning '", 20);
		write(STDERR_FILENO, error, ft_strlen(error));
	}
	if (func || error)
		write(STDERR_FILENO, "'\n", 2);
	return (NULL);
}

// calls va_end, prints given error and returns -1.
short	ft_error_minone(const char *error, const char *func, va_list *pva)
{
	if (pva)
		va_end(*pva);
	if (func)
	{
		write(STDERR_FILENO, "\nAn error occured in '", 22);
		write(STDERR_FILENO, func, ft_strlen(func));
	}
	if (error)
	{
		write(STDERR_FILENO, "'\nError concerning '", 20);
		write(STDERR_FILENO, error, ft_strlen(error));
	}
	if (func || error)
		write(STDERR_FILENO, "'\n", 2);
	return (-1);
}
