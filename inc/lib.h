/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:44:15 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 17:34:21 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdlib.h>

typedef struct s_conv
{
	int		min_width;
	int		precision;
	char	alignment;
	char	filler;
	char	sign;
	char	alt;
	char	space;
	char	uphex;
	char	mod;
}	t_conv;

void	conv_init(t_conv *conv);
/*
 *	string functions
 */
int		contains(const char *str, const char c);
int		ft_isdigit(const char c);
size_t	ft_strlen(const char *str);
char	*ft_itoa(long long n);
char	*ft_uitoa(unsigned long long n);
char	*ft_uitohex(unsigned long long n, char upper/*, char alt*/);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif /*LIB_H*/
