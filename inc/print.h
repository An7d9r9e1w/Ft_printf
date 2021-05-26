/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnamor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:14:17 by nnamor            #+#    #+#             */
/*   Updated: 2021/04/27 11:56:40 by nnamor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# include <stdarg.h>
# include <unistd.h>
# include "lib.h"

# define MAX_INT 2147483647

int	print_char(va_list *ap, t_conv conv);
int	print_nos(const char c, t_conv conv);
int	print_proc(va_list *ap, t_conv conv);
int	print_str(va_list *ap, t_conv conv);
int	print_int(va_list *ap, t_conv conv);
int	print_uint(va_list *ap, t_conv conv);
int	print_hex(va_list *ap, t_conv conv);
int	print_uphex(va_list *ap, t_conv conv);
int	print_ptr(va_list *ap, t_conv conv);

int	print_float(va_list *ap, t_conv conv);
#endif /*PRINT_H*/
