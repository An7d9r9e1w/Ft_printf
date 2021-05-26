/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:12:30 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 12:06:34 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "ftoa_bonus.h"

static int	write_with_args(const char *str, t_conv conv, int len)
{
	if (!conv.alignment)
		while (conv.min_width-- > 0)
			if (write(1, &conv.filler, 1) < 0)
				return (-1);
	if (write(1, str, len) < 0)
		return (-1);
	if (conv.alignment)
		while (conv.min_width-- > 0)
			if (write(1, &conv.filler, 1) < 0)
				return (-1);
	return (0);
}

static int	print(const char *str, t_conv conv)
{
	int	bytes;
	int	len;

	len = ft_strlen(str);
	if (conv.min_width > len)
		bytes = conv.min_width;
	else
		bytes = len;
	conv.min_width -= len;
	if (write_with_args(str, conv, len) < 0)
		bytes = -1;
	return (bytes);
}

int	print_float(va_list *ap, t_conv conv)
{
	char	str[128];

	if (conv.precision < 0)
		conv.precision = 6;
	ftoa((float)va_arg(*ap, double), str, conv.precision);
	return (print(str, conv));
}
