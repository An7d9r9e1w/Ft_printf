/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:43:06 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 14:56:04 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftoa_bonus.h"

int	powi(int num, int power)
{
	int	res;

	res = 1;
	while (power > 0)
	{
		if (power & 1)
			res *= num;
		power >>= 1;
		num *= num;
	}
	return (res * (!power));
}

static void	reverse(char *str, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < len)
	{
		tmp = str[i];
		str[i++] = str[--len];
		str[len] = tmp;
	}
}

static int	uitoa(unsigned long long num, char *str)
{
	int	i;

	if (!num)
	{
		*str = '0';
		return (1);
	}
	i = 0;
	while (num)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	reverse(str, i);
	return (i);
}

static int	nani(float f, char *str)
{
	const t_un	un = {.f = f};

	if ((un.i & 0x7f800000) == 0x7f800000)
	{
		if (un.i == 0x7f800000 || un.i == 0xff800000)
		{
			*str++ = 'i';
			*str++ = 'n';
			*str++ = 'f';
			*str = 0;
		}
		else
		{
			*str++ = 'n';
			*str++ = 'a';
			*str++ = 'n';
			*str = 0;
		}
		return (1);
	}
	return (0);
}

void	ftoa(float f, char *str, int prec)
{
	const t_un	un = {.f = f};
	int			tmp;

	if (nani(f, str))
		return ;
	if (un.i >> 31)
	{
		*str++ = '-';
		f = -f;
	}
	str += uitoa((unsigned long long)f, str);
	if (prec > 0)
	{
		*str++ = '.';
		f -= (unsigned long long)f;
		f = f * powi(10, prec);
		tmp = uitoa((unsigned long long)f, str);
		str += tmp;
		prec -= tmp;
		while (prec--)
			*str++ = '0';
	}
	*str = 0;
}
