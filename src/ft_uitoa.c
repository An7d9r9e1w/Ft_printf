/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:34:03 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 17:00:54 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
//#include "libftprintf.h"

char	*ft_uitoa(unsigned long long n)
{
	char	*res;
	char	str[21];
	short	len;

	str[20] = 0;
	str[19] = '0';
	len = 19 + (n != 0);
	while (n && len--)
	{
		str[len] = n % 10 + '0';
		n /= 10;
	}
	res = (char *)malloc(sizeof(char *) * (21 - len));
	ft_strlcpy(res, str + len, 21 - len);
	return (res);
}
