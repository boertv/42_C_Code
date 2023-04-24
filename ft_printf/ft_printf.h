/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:31:49 by bvercaem          #+#    #+#             */
/*   Updated: 2023/04/19 15:31:51 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int     ft_printf(const char *format, ...);
void    *ft_error_null(const char *error, const char *function, va_list *ptr_spec);
char    *ft_conversion_char(char *sub_format, va_list *ptr_spec);
int     ft_field_width(char *sub_format);
int     ft_precision(char *sub_format);
int     ft_left_just(char *sub_format);
int     ft_zeroes(char *sub_format);
int     ft_hashtag(char *sub_format);
int     ft_plus(char *sub_format);
int     ft_space(char *sub_format);
int     ft_check_char(char *sub_format);

#endif
