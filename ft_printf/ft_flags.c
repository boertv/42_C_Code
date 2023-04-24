/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:11:57 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 12:12:56 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// returns 0 for no flag, -1 on error
int	ft_field_width(char *sub_format)
{
    int fw;

    fw = 0;
    while (*sub_format)
    {
        if (*sub_format == '.')
            while (*sub_format >= '0' && *sub_format <= '9')
                sub_format++;
        if (*sub_format >= '1' && *sub_format <= '9')
        {
            fw = ft_atoi_overflow(sub_format);
            while (*sub_format >= '0' && *sub_format <='9')
                sub_format++;
            break;
        }
        sub_format++;
    }
    if (!*sub_format || !ft_strchr("cspdiuxX%.", *sub_format))
        return (-1);
    return (fw);
}

// returns 0 for no flag, -1 on error, -2 for flag of size 0
int ft_precision(char *sub_format)
{
    int pr;

    pr = 0;
    while (*sub_format)
    {
        if (*sub_format == '.')
        {
            sub_format++;
            while (*sub_format == '0')
                sub_format++;
            if (*sub_format >= '1' && *sub_format <= '9')
            {
                pr = ft_atoi_overflow(sub_format);
                while (*sub_format >= '0' && *sub_format <='9')
                    sub_format++;
            }
            else
                pr = -2;
            break;
        }
        sub_format++;
    }
    if (!*sub_format || !ft_strchr("cspdiuxX%", *sub_format))
        return (-1);
    return (pr);
}

static int ft_atoi_overflow(char *sub_format)
{
    int nb;

    nb = ft_atoi(sub_format);
        if (!nb || nb == 2147483647)
            nb = -1;
    return (nb);
}

// returns 0 for no flag, -1 on error
int ft_left_just(char *sub_format)
{
    int i;
    int l;

    i = 0;
    l = 0;
    while (sub_format[i])
    {
        if (sub_format[i] == '-')
        {
            l = 1;
            if (i && (sub_format[i - 1] == '.' || (sub_format[i - 1] >= '0' && sub_format[i - 1] <= '9')))
                return (-1);
        }
        i++;
    }
    return (l);
}
