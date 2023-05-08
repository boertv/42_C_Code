/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:17:15 by bvercaem          #+#    #+#             */
/*   Updated: 2023/05/08 14:48:10 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		flen++;
	while ((*pform)[flen] && !ft_strchr("cspdiuxX%", (*pform)[flen]))
		flen++;
	if ((*pform)[flen] && ft_strchr("cspdiuxX%", (*pform)[flen]))
		flen++;
	sform = ft_substr(*pform, 0, flen);
	if (!sform)
		return (NULL);
	*pform += flen;
	return (sform);
}

// returns -1 on failure, else returns 0
static short	ft_writing(char *to_print, int *mlen, int *rlen, va_list *pva)
{
	int	check;

	if (!to_print)
		return (-1);
	check = write(1, to_print, *mlen);
	free (to_print);
	if (check == -1)
		return (ft_error_minone("write", "writing", pva));
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
			return (ft_error_minone("cut_format", "printf", &va));
		to_print = ft_conv_hub(sform, &mlen, &va);
		free(sform);
		if (ft_writing(to_print, &mlen, &rlen, &va))
			return (-1);
	}
	va_end(va);
	return (rlen);
}
