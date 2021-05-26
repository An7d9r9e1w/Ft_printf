/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:34:37 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 16:49:04 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "set_attr.h"
//#include "libftprintf.h"

void	set_width(t_conv *conv, const char **format, va_list *ap)
{
	const char	*fmtcp;
	int			width;

	(void)ap;
	fmtcp = *format;
	width = 0;
	while (ft_isdigit(*fmtcp) && width >= 0)
		width = width * 10 + *fmtcp++ - '0';
	if (width < 0)
		conv->min_width = MAX_INT;
	else
		conv->min_width = width;
	while (ft_isdigit(*fmtcp))
		fmtcp++;
	*format = fmtcp;
}

void	set_width_by_arg(t_conv *conv, const char **format, va_list *ap)
{
	int	width;

	width = va_arg(*ap, int);
	if (width < 0)
	{
		set_alignment(conv, format, ap);
		width = -width;
	}
	conv->min_width = width;
}

void	set_precision(t_conv *conv, const char **format, va_list *ap)
{
	const char	*fmtcp;
	int			width;

	fmtcp = *format;
	if (*fmtcp == '*')
	{
		conv->precision = va_arg(*ap, int);
		++*format;
		return ;
	}
	width = 0;
	while (ft_isdigit(*fmtcp))
		width = width * 10 + *fmtcp++ - '0';
	if (width < 0)
		conv->precision = MAX_INT;
	else
		conv->precision = width;
	*format = fmtcp;
}

void	set_alignment(t_conv *conv, const char **format, va_list *ap)
{
	(void)format;
	(void)ap;
	conv->alignment = 1;
	if (conv->filler == '0')
		conv->filler = ' ';
}

void	set_filler(t_conv *conv, const char **format, va_list *ap)
{
	(void)format;
	(void)ap;
	if (!conv->alignment)
		conv->filler = '0';
}
