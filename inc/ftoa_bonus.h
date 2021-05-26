/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 10:49:29 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 14:48:15 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTOA_BONUS_H
# define FTOA_BONUS_H

typedef union u_un
{
	float			f;
	unsigned int	i;
}	t_un;

void	ftoa(float f, char *str, int prec);
int		powi(int num, int power);
#endif	/*FTOA_BONUS_H*/
