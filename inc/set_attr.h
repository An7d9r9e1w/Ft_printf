/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_attr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:34:20 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/26 18:03:52 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_ATTR_H
# define SET_ATTR_H

# include "lib.h"

# define MAX_INT 2147483647

void	set_width(t_conv *conv, const char **format, va_list *ap);
void	set_width_by_arg(t_conv *conv, const char **format, va_list *ap);
void	set_precision(t_conv *conv, const char **format, va_list *ap);
void	set_alignment(t_conv *conv, const char **format, va_list *ap);
void	set_filler(t_conv *conv, const char **format, va_list *ap);

void	set_sign(t_conv *conv, const char **format, va_list *ap);
void	set_alt(t_conv *conv, const char **format, va_list *ap);
void	set_space(t_conv *conv, const char **format, va_list *ap);
void	set_hmod(t_conv *conv, const char **format, va_list *ap);
void	set_lmod(t_conv *conv, const char **format, va_list *ap);
#endif
