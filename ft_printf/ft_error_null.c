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

void    *ft_error_null(const char *error, const char *function, va_list *specifier)
{
    va_end(*specifier);
    if (!function)
        return (NULL);
    write(0, "\nAn error occured in '", 22);
    while (*function)
    {
        write(0, function, 1);
        function++;
    }
    write(0, "' concerning the '", 18);
    while (*error)
    {
        write(0, error, 1);
        error++;
    }
    write(0, "'\n", 2);
    return (NULL);
}
