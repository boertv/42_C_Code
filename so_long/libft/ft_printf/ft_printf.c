/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvercaem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:17:15 by bvercaem          #+#    #+#             */
/*   Updated: 2023/07/07 16:15:41 by bvercaem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_fd(const char **pform, va_list *pva)
{
	int	fd;

	if ((*pform)[0] != '%')
		return (STDOUT_FILENO);
	if ((*pform)[1] != 'f')
		return (STDOUT_FILENO);
	if ((*pform)[2] != 'd')
		return (STDOUT_FILENO);
	fd = va_arg(*pva, int);
	*pform += 3;
	return (fd);
}

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
static short	ft_output(t_to_print to_print, int *mlen, int *rlen)
{
	int	check;

	if (!to_print.str)
		return (-1);
	check = write(to_print.fd, to_print.str, *mlen);
	free (to_print.str);
	if (check == -1)
		return (ft_error_minone("write", "output", NULL));
	*rlen += check;
	return (0);
}

// if the format starts with '%fd' the provided fd is used, else the stdout.
int	ft_printf(const char *format, ...)
{
	va_list		va;
	int			rlen;
	char		*sform;
	t_to_print	to_print;
	int			mlen;

	if (!format)
		return (ft_error_minone("NULL format", "ft_printf", NULL));
	rlen = 0;
	va_start(va, format);
	to_print.fd = ft_conv_fd(&format, &va);
	if (to_print.fd < 1 || to_print.fd > FOPEN_MAX)
		return (ft_error_minone("fd", "ft_printf", &va));
	while (*format)
	{
		sform = ft_cut_format(&format);
		if (!sform)
			return (ft_error_minone(NULL, NULL, &va));
		to_print.str = ft_conv_hub(sform, &mlen, &va);
		free(sform);
		if (ft_output(to_print, &mlen, &rlen))
			return (ft_error_minone(NULL, NULL, &va));
	}
	va_end(va);
	return (rlen);
}
