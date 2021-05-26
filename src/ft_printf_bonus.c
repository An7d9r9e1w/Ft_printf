/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 14:41:10 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 17:12:49 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "print.h"
#include "set_attr.h"

static void	get_attr(const char **format, va_list *ap, t_conv *conv)
{
	static const char		flags[] = "-0.*# +hl";
	static	void (*const	set[])(t_conv *, const char **,
							va_list *) = {&set_alignment, &set_filler,
							&set_precision, &set_width_by_arg, &set_alt,
							&set_space, &set_sign, &set_hmod, &set_lmod};
	int						i;
	char					flag;

	flag = **format;
	if (flag >= '1' && flag <= '9')
	{
		set_width(conv, format, ap);
		return ;
	}
	i = 0;
	while (flag != flags[i])
		i++;
	++*format;
	set[i](conv, format, ap);
}

static int	conv_parser(const char **format, va_list *ap)
{
	static const char	specifiers[] = "cspdiuxX%";
	static	int (*const	print[])(va_list *, t_conv) = {&print_char,
						&print_str,	&print_ptr, &print_int, &print_int,
						&print_uint, &print_hex, print_uphex, &print_proc};
	t_conv				conv;
	const char			*fmtcp;
	int					i;

	conv_init(&conv);
	fmtcp = *format + 1;
	while (*fmtcp && (contains("-0.*# +lh", *fmtcp) || ft_isdigit(*fmtcp)))
		get_attr(&fmtcp, ap, &conv);
	*format = fmtcp;
	if (**format)
		++*format;
	i = 0;
	while (specifiers[i] && *fmtcp != specifiers[i])
		i++;
	if (specifiers[i])
		return (print[i](ap, conv));
	if (*fmtcp)
		return (print_nos(*fmtcp, conv));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		bytes;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	bytes = 0;
	while (*format && bytes >= 0 && count >= 0)
	{
		if (*format == '%')
			bytes = conv_parser(&format, &ap);
		else
			bytes = write(1, format++, 1);
		count += bytes;
	}
	va_end(ap);
	if (bytes < 0 || count < 0)
		return (-1);
	else
		return (count);
}
