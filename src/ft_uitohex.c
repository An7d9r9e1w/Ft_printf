/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitohex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 16:16:47 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 16:57:40 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
//#include "libftprintf.h"

char	*ft_uitohex(unsigned long long n, char upper)
{
	char	*res;
	char	str[18];
	short	len;
	char	tmp;

	str[17] = 0;
	str[16] = '0';
	len = 16 + (n != 0);
	upper = 'A' * upper + 'a' * !upper - 10;
	while (n && --len)
	{
		tmp = n % 16;
		if (tmp < 10)
			tmp += '0';
		else
			tmp += upper;
		str[len] = tmp;
		n /= 16;
	}
	/*str[len - 1] = 'x';
	str[len - 2] = '0';
	len -= alt << 1;*/
	res = (char *)malloc(sizeof(char *) * (18 - len));
	ft_strlcpy(res, str + len, 18 - len);
	return (res);
}
