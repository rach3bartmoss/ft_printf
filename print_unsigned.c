/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:37:07 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/22 21:28:29 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	ft_putstr(const char *str, t_list *op)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
		op->count++;
	}
}

void	print_unsigned(t_flags *flags, t_list *op)
{
	char			*str;
	unsigned int	value;
	int				len;
	int				padding;

	value = va_arg(op->ap, unsigned int);
	str = ft_itoa_custombase(value, 10);
	if (!str)
		return ;
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision > len)
		len = flags->precision;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	if (flags->padding != ' ' && flags->padding != '0' && padding > 0)
		print_padding(padding, ' ', op);
	if (flags->precision > 0)
		print_padding(flags->precision - ft_strlen(str), '0', op);
	if (flags->padding == '0' && padding > 0 && flags->precision < 0)
		print_padding(padding, '0', op);
	ft_putstr(str, op);
	if (flags->padding == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}
