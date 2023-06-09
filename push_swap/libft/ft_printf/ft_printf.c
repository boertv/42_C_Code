/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:17:15 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/11 17:00:00 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	ft_check_spec(const char *format, const char *set)
{
	while (*format)
	{
		if (ft_strchr(set, *format))
			return (1);
		format++;
	}
	return (0);
}

// returns NULL on error, char* on success
static char	*ft_cut_format(const char **pform)
{
	char	*sform;
	int		flen;

	if (!pform)
		return (NULL);
	flen = 0;
	while ((*pform)[flen] && (*pform)[flen] != '%')
		flen++;
	if ((*pform)[flen] == '%')
	{
		flen++;
		if (!ft_check_spec(*pform + flen, SPECIFIERS))
			return (ft_error_null("no specifier", "cut_format", NULL));
	}
	while ((*pform)[flen] && !ft_strchr(SPECIFIERS, (*pform)[flen]))
		flen++;
	if ((*pform)[flen] && ft_strchr(SPECIFIERS, (*pform)[flen]))
		flen++;
	sform = ft_substr(*pform, 0, flen);
	if (!sform)
		return (ft_error_null("ft_substr", "cut_format", NULL));
	*pform += flen;
	return (sform);
}

// returns -1 on failure, else returns 0
static short	ft_output(char *to_print, int *mlen, int *rlen)
{
	int	check;

	if (!to_print)
		return (-1);
	check = write(1, to_print, *mlen);
	free (to_print);
	if (check == -1)
		return (ft_error_minone("write", "output", NULL));
	*rlen += check;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	int		rlen;
	char	*sform;
	char	*to_print;
	int		mlen;

	if (!format)
		return (-1);
	rlen = 0;
	va_start(va, format);
	while (*format)
	{
		sform = ft_cut_format(&format);
		if (!sform)
			return (ft_error_minone(NULL, NULL, &va));
		to_print = ft_conv_hub(sform, &mlen, &va);
		free(sform);
		if (ft_output(to_print, &mlen, &rlen))
			return (ft_error_minone(NULL, NULL, &va));
	}
	va_end(va);
	return (rlen);
}
