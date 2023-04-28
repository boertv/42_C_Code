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

int		ft_printf(const char *format, ...);
void	*ft_error_null(const char *error, const char *func, va_list *ptr_spec);
char	*ft_conv_char(char *sub_format, va_list *ptr_spec, char c);
char	*ft_conv_str(char *sub_format, va_list *ptr_spec);
char	*ft_conv_nb(char *sub_format, va_list *ptr_spec, char *base, int sign);
char	*ft_conv_ptr(char *sub_format, va_list *ptr_spec);
int		ft_field_width(char *sub_format);
int		ft_precision(char *sub_format);
int		ft_left_just(char *sub_format);
int		ft_zeroes(char *sub_format);
int		ft_hashtag(char *sub_format);
int		ft_plus(char *sub_format);
int		ft_space(char *sub_format);
int		ft_check_char(char *sub_format);
int		ft_check_nb(char *sub_format, int baselen, int sign);

typedef struct s_nb_attr
{
	long	nb;
	int		nblen;
	char	*base;
	int		baselen;
	int		fw;
	int		pr;
}				t_nb_attr;

int		ft_nblen(char *sub_format, long nb, int baselen, int sign);
void	ft_fill_nbstruct(char *sf, t_nb_attr *snb, int sign);
void	ft_fill_nb(char *dst, char *sub_format, t_nb_attr *snb, int sign);
void	ft_putnbr_str(char *sub_format, char *dst, t_nb_attr *snb, int sign);
void	ft_putnchr(char *dst, char c, int n);

#endif
