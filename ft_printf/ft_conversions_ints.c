/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_ints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:23:39 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/25 16:24:40 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_conversion_int(char *sub_format, va_list *ptr_spec)
{
    size_t  len;

    len = 0;
    while (sub_format[len] && (sub_format[len] != '%'))
        len++;
    if (ft_check_int(sub_format + len) == -1)
        return (ft_error_null("flags", "ft_conversion_str", ptr_spec));
    // calculate nb length for field_width < nb_len and calloc
    // FREE nb_str after copying to to_print
}
