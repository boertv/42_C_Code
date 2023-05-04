/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:20:42 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/21 16:20:44 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_error_null(const char *error, const char *func, va_list *ptr_va)
{
	va_end(*ptr_va);
	return (NULL);
	if (!func || !error)
		return (NULL);
	write(1, "\nAn error occured in '", 22);
	write(1, func, ft_strlen(func));
	write(1, "' concerning the '", 18);
	write(1, error, ft_strlen(error));
	write(1, "'\n", 2);
	return (NULL);
}
