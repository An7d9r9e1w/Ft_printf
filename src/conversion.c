/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 10:59:39 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 17:34:48 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
//#include "libftprintf.h"

void	conv_init(t_conv *conv)
{
	conv->min_width = 0;
	conv->precision = -1;
	conv->alignment = 0;
	conv->filler = ' ';
	conv->sign = 0;
	conv->alt = 0;
	conv->space = 0;
	conv->uphex = 0;
	conv->mod = -1;
}
