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

void	*ft_error_null(const char *error, const char *func, va_list *ptr_spec)
{
	va_end(*ptr_spec);
	return (NULL);
	if (!func)
		return (NULL);
	write(0, "\nAn error occured in '", 22);
	write(0, func, ft_strlen(func));
	write(0, "' concerning the '", 18);
	write(0, error, ft_strlen(error));
	write(0, "'\n", 2);
	return (NULL);
}
