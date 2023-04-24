/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:46:37 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/24 14:46:39 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// no errors possible in most of these functions
int ft_zeroes(char *sub_format)
{
    int i;

    i = 0;
    while (sub_format[i])
    {
        if (sub_format[i] == '0' && (!i
            || sub_format[i - 1] <= '0' || sub_format[i - 1] >= '9'))
            return (1);
        i++;
    }
    return (0);
}

int ft_hashtag(char *sub_format)
{
    while (*sub_format)
    {
        if (*sub_format == '#')
            return (1);
        sub_format++;
    }
    return (0);
}

int ft_plus(char *sub_format)
{
    while (*sub_format)
    {
        if (*sub_format == '+')
            return (1);
        sub_format++;
    }
    return (0);
}

// -1 on error: if '+' is present
int ft_space(char *sub_format)
{
    int p;

    p = ft_plus(sub_format);
    while (*sub_format)
    {
        if (*sub_format == ' ')
        {
            if (p)
                return (-1);
            return (1);
        }
        sub_format++;
    }
    return (0);
}
