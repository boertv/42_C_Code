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
void	*ft_error_null(const char *error, const char *func, va_list *ptr_va);
char	*ft_conv_char(char *sform, va_list *ptr_va, char c, size_t *printlen);
char	*ft_conv_str(char *sform, va_list *ptr_va);
char	*ft_conv_nb(char *sform, va_list *ptr_va, char *base, int sign);
char	*ft_conv_ptr(char *sform, va_list *ptr_va);
int		ft_field_width(char *sform);
int		ft_precision(char *sform);
int		ft_left_just(char *sform);
int		ft_zeroes(char *sform);
int		ft_hashtag(char *sform);
int		ft_plus(char *sform);
int		ft_space(char *sform);

typedef struct s_str_attr
{
	char	*str;
	int		pr;
	int		fw;
}			t_str_attr;

int		ft_check_char(char *sform);
int		ft_check_str(char *sform);
void	ft_fill_char_print(char *dst, char c, int fw, int lj);
void	ft_fill_str_print(char *dst, t_str_attr *sstr, int lj);

typedef struct s_nb_attr
{
	unsigned long	unb;
	long			lnb;
	int				sign;
	int				nblen;
	char			*base;
	int				baselen;
	int				fw;
	int				pr;
}					t_nb_attr;

int		ft_check_nb(char *sform, int baselen, int sign);
int		ft_lnblen(char *sform, long nb, int baselen);
int		ft_unblen(char *sform, unsigned long nb, int baselen);
void	ft_fill_nbstruct(char *sf, t_nb_attr *snb, int sign, int ptr_ind);
void	ft_fill_nb(char *dst, char *sform, t_nb_attr *snb, int ptr_ind);
void	ft_putnbr_str(char *dst, t_nb_attr *snb);
void	ft_write_sign(char *sform, char *dst, long nb, int sign);
void	ft_putnchr(char *dst, char c, int n);

#endif
