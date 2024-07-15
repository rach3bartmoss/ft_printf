/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:17:13 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/13 01:30:21 by dopereir         ###   ########.fr       */
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

void	print_octal(t_flags *flags, t_list *op)
{
	char	*str;

	auto unsigned int value = va_arg(op->ap, unsigned int);
	str = ft_itoa_custombase(value, 8);
	auto int len = ft_strlen(str);
	auto int prefix_len = 0;
	if (flags->padding == '#' && value != 0)
		prefix_len = 1;
	if (flags->precision >= 0 && flags->precision > len)
		len = flags->precision;
	auto int padding = 0;
	if (flags->width > len + prefix_len)
		padding = flags->width - (len + prefix_len);
	if (flags->padding != '-' && flags->padding != '0' && padding > 0)
		print_padding(padding, ' ', op);
	if (prefix_len)
		ft_putchar('0');
	if (flags->precision > 0)
		print_padding(flags->precision - ft_strlen(str), '0', op);
	if (flags->padding == '0' && padding > 0 && flags->precision < 0)
		print_padding(padding, '0', op);
	ft_putstr(str, op);
	if (flags->padding == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}
