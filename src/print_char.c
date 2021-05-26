/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:18:26 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/25 15:09:42 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
//#include "libftprintf.h"

static int	print(const char *str, t_conv conv, int	len)
{
	int	bytes;
	int	i;

	if (conv.min_width >= MAX_INT - 1)
		return (-1);
	i = len;//ft_strlen(str);
	if (conv.precision >= 0 && i > conv.precision)
		i = conv.precision;
	if (conv.min_width > i)
		bytes = conv.min_width;
	else
		bytes = i;
	if (conv.alignment)
		if (write(1, str, i) < 0)
			return (-1);
	while (conv.min_width-- > i)
		if (write(1, &conv.filler, 1) < 0)
			return (-1);
	if (!conv.alignment)
		if (write(1, str, i) < 0)
			return (-1);
	return (bytes);
}

int	print_nos(const char c, t_conv conv)
{
	const char	str[2] = {(char)c, 0};

	conv.precision = -1;
	return (print((const char *)str, conv, 1));
}

int	print_char(va_list *ap, t_conv conv)
{
	const char	str[2] = {(char)va_arg(*ap, int), 0};

	conv.precision = -1;
	return (print((const char *)str, conv, 1));
}

int	print_proc(va_list *ap, t_conv conv)
{
	(void)ap;
	conv.precision = -1;
	return (print("%", conv, 1));
}

int	print_str(va_list *ap, t_conv conv)
{
	char	*str;

	if (conv.min_width >= MAX_INT - 1)
		return (-1);
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";//return (write(1, "(null)", 6));
	return (print(str, conv, ft_strlen(str)));
}
