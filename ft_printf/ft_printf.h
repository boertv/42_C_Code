/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:20:21 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/11 16:44:00 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

# define SPECIFIERS "cspdiuxX%"

typedef struct s_flag
{
	char	*sform;
	int		fw;
	int		pr;
	short	lj;
	short	zs;
	short	ht;
	short	sp;
	short	pl;
}		t_flag;

typedef struct s_nb_attr
{
	short			s;
	unsigned long	unb;
	long			lnb;
	int				nblen;
	const char		*base;
	int				baselen;
	char			sign;
}					t_nb_attr;

int		ft_printf(const char *format, ...);
short	ft_error_minone(const char *error, const char *func, va_list *p_va);
void	*ft_error_null(const char *error, const char *func, va_list *p_va);
char	*ft_conv_hub(char *sform, int *mlen, va_list *pva);
int		ft_field_width(char *sform);
int		ft_precision(char *sform);
short	ft_left_just(char *sform);
short	ft_zeroes(char *sform);
short	ft_hashtag(char *sform);
short	ft_plus(char *sform);
short	ft_space(char *sform);
short	ft_flag_errors(t_flag *pflag);
short	ft_flag_str(t_flag *pflag);
short	ft_flag_char(t_flag *pflag);
short	ft_flag_nb(t_flag *pflag, t_nb_attr *pnb);
void	ft_putnfw(char *dst, short zs, int n);
char	*ft_conv_char(t_flag *flag, int *mlen, va_list *pva);
char	*ft_conv_mod(t_flag *flag, int *mlen, va_list *pva);
char	*ft_conv_str(t_flag *flag, int *mlen, va_list *pva);
char	*ft_conv_nb(t_flag *flag, t_nb_attr *nb, int *mlen, va_list *pva);
char	*ft_conv_ptr(t_flag *flag, t_nb_attr *nb, int *mlen, va_list *pva);
void	ft_fill_nb(char *to_print, t_flag *flag, t_nb_attr *nb, int *mlen);

#endif
