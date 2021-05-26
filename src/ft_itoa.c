/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:39:53 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 17:13:44 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_itoa(long long n)
{
	char				*res;
	char				str[21];
	unsigned long long	un;
	short				len;

	str[20] = 0;
	str[19] = '0';
	len = 19 + (n != 0);
	if (n < 0)
		un = -n;
	else
		un = n;
	while (un && --len)
	{
		str[len] = un % 10 + '0';
		un /= 10;
	}
	str[len - 1] = '-';
	len -= (n < 0);
	res = (char *)malloc(sizeof(char *) * (21 - len));
	ft_strlcpy(res, str + len, 21 - len);
	return (res);
}
