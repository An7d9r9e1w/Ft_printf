/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:40:50 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 17:01:13 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
//#include "libftprintf.h"

static int	write_with_args(const char *str, int len, t_conv conv)
{
	if (conv.space && (write(1, " ", 1) < 0))
		return (-1);
	if (conv.filler == ' ' && !conv.alignment)
		while (conv.min_width-- > 0)
			if (write(1, &conv.filler, 1) < 0)
				return (-1);
	if ((conv.alt && ((conv.uphex && write(1, "0X", 2) < 0) 
		|| (!conv.uphex && write(1, "0x", 2) < 0)))
		|| (conv.sign && write(1, &conv.sign, 1) < 0))
		return (-1);
	while (conv.precision-- > 0)
		if (write(1, "0", 1) < 0)
			return (-1);
	if (conv.filler == '0')
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

int	print(const char *str, t_conv conv)
{
	int	bytes;
	int	len;

	if (!str || conv.min_width >= MAX_INT - 1 || conv.precision >= MAX_INT - 1)
		return (-1);
	if (conv.precision >= 0 || conv.alignment)
		conv.filler = ' ';
	len = ft_strlen(str);
	bytes = len;
	if (conv.precision > bytes)
		bytes = conv.precision;
	bytes += (conv.alt << 1) + (conv.sign || conv.space);
	if (conv.min_width > bytes)
		bytes = conv.min_width;
	if (len > conv.precision)
		conv.min_width -= len + (conv.alt << 1) + (conv.sign || conv.space);
	else
		conv.min_width -= conv.precision + (conv.alt << 1) + (conv.sign || conv.space);
	conv.precision -= len;
	if (write_with_args(str, len, conv) < 0)
		bytes = -1;
	free((char *)str);
	return (bytes);
}

int	print_int(va_list *ap, t_conv conv)
{
	char		*str;
	long long	num;

	if (!conv.mod)
		num = (char)va_arg(*ap, int);
	else if (conv.mod == 1)
		num = (short)va_arg(*ap, int);
	else if (conv.mod == 2)
		num = va_arg(*ap, long);
	else if (conv.mod == 3)
		num = va_arg(*ap, long long);
	else
		num = va_arg(*ap, int);
	if (num < 0)
	{
		conv.sign = '-';
		conv.space = 0;
		num = -num;
	}
	str = ft_uitoa(num);
	if (str && *str == '0' && !conv.precision)
		*str = 0;
	return (print(str, conv));
}

int	print_uint(va_list *ap, t_conv conv)
{
	char		*str;
	unsigned long long	num;

	if (!conv.mod)
		num = (unsigned char)va_arg(*ap, unsigned int);
	else if (conv.mod == 1)
		num = (unsigned short)va_arg(*ap, unsigned int);
	else if (conv.mod == 2)
		num = va_arg(*ap, unsigned long);
	else if (conv.mod == 3)
		num = va_arg(*ap, unsigned long long);
	else
		num = va_arg(*ap, unsigned int);
	str = ft_uitoa(num);
	if (str && *str == '0' && !conv.precision)
		*str = 0;
	return (print(str, conv));
}
