/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:10:16 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/24 22:28:18 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "print.h"
# include "set_attr.h"

const char		g_specifiers[] = "cspdiuxX%";
const char		g_flags[] = "-0.*";
int (*const		g_print[])(va_list *, t_conv) = {&print_char,		/* c */
													&print_str,		/* s */
													&print_ptr,		/* p */
													&print_int,		/* d */
													&print_int,		/* i */
													&print_uint,	/* u */
													&print_hex,		/* x */
													&print_uphex,	/* X */
													&print_proc};	/* % */

void (*const	g_set[])(t_conv *, const char **,
									va_list *) = {&set_alignment,	/* - */
												&set_filler,		/* 0 */
												&set_precision,		/* . */
												&set_width_by_arg};	/* * */
#endif /*FT_PRINTF_H*/
