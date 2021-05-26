/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:24:59 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/25 14:38:16 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
//#include "libftprintf.h"

int	contains(const char *str, const char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}

int	ft_isdigit(const char c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	if (!dst || !src)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize)
	{
		if (dstsize > srcsize + 1)
			dstsize = srcsize + 1;
		i = 0;
		while (i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (srcsize);
}
