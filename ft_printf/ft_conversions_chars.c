/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_chars.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:08:54 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 13:08:57 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_fill_char_specifier(char *dst, va_list *ptr_spec, int fw, int lj)
{
    char    c;

    c = (char) va_arg(*ptr_spec, int);
    while (*dst)
        dst++;
    if (lj)
    {
        *dst = c;
        dst++;
    }
    while (--fw)
    {
        *dst = ' ';
        dst++;
    }
    if (!lj)
        *dst = c;
    return ;
}

char    *ft_conversion_char(char *sub_format, va_list *ptr_spec)
{
    size_t  len;
    int     field_width;
    char    *to_print;

    len = 0;
    while (sub_format[len] && (sub_format[len] != '%'))
        len++;
    if (ft_check_char(sub_format + len) == -1)
        return (ft_error_null("ft_conversion_char", "flags", ptr_spec));
    field_width = ft_field_width((sub_format + len));
    if (!field_width)
        field_width = 1;
    len += field_width;
    to_print = calloc(len + 1, sizeof(char));
    if (!to_print)
        return (ft_error_null("ft_conversion_char", "calloc", ptr_spec));
    ft_strlcpy(to_print, sub_format, len - field_width + 1);
    ft_fill_char_specifier(to_print, ptr_spec,
        field_width, ft_left_just(sub_format + len - field_width));
    return (to_print);
}
