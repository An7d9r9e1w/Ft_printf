/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:39:07 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 18:02:13 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
//#include "libftprintf.h"

/*static int	print(unsigned long long num, t_conv conv, char upper)
{
	char	*str;

	conv.filler = 0;
	str = ft_uitohex(num, upper);
	if (!str)
		return (-1);
	num = write(1, str, ft_strlen(str));
	free(str);
	return ((int)num);
}*/
int	print(const char *str, t_conv conv);

int	print_hex(va_list *ap, t_conv conv)
{
	char				*str;
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
	str = ft_uitohex(num, 0);
	if (str && *str == '0')
	{
		*str *= conv.precision != 0;
		conv.alt = 0;
	}
	conv.uphex = 0;
	return (print(str, conv));
	//return (print(va_arg(*ap, unsigned int), conv));
}

int	print_uphex(va_list *ap, t_conv conv)
{
	char				*str;
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
	str = ft_uitohex(num, 1);
	if (str && *str == '0')
	{
		*str *= conv.precision != 0;
		conv.alt = 0;
	}
	conv.uphex = 1;
	return (print(str, conv));
	//return (print(va_arg(*ap, unsigned int), conv));
}

int	print_ptr(va_list *ap, t_conv conv)
{
	char	*str;
	
	conv.alt = 1;
	str = ft_uitohex(va_arg(*ap, unsigned long long), 0);
	if (str && *str == '0' && !conv.precision)
		*str = 0;
	return (print(str, conv));
	//return (print(va_arg(*ap, unsigned long long), conv));
}
