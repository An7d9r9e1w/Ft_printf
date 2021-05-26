/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:49:46 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 16:48:25 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "set_attr.h"
//#include "libftprintf.h"

void	set_hmod(t_conv *conv, const char **format, va_list *ap)
{
	(void)ap;
	if (**format == 'h')
	{
		++*format;
		conv->mod = 0;
	}
	else
		conv->mod = 1;
}

void	set_lmod(t_conv *conv, const char **format, va_list *ap)
{
	(void)ap;
	if (**format == 'l')
	{
		++*format;
		conv->mod = 3;
	}
	else
		conv->mod = 2;
}

void	set_sign(t_conv *conv, const char **format, va_list *ap)
{
	(void)format;
	(void)ap;
	conv->sign = '+';
	conv->space = 0;
}

void	set_alt(t_conv *conv, const char **format, va_list *ap)
{
	(void)format;
	(void)ap;
	conv->alt = 1;
}

void	set_space(t_conv *conv, const char **format, va_list *ap)
{
	(void)format;
	(void)ap;
	if (!conv->sign)
		conv->space = 1;
}
