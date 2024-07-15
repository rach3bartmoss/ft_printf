/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:40:33 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/15 20:49:08 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	print_sign(t_flags *flags)
{
	if (flags->padding == '+')
		ft_putchar('+');
	else if (flags->padding == ' ')
		ft_putchar(' ');
}

static void	print_integer_str(const char *str, t_list *op)
{
	auto int i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
		op->count++;
	}
}

void	print_int(t_flags *flags, t_list *op)
{
	char	*str;

	auto int value = va_arg(op->ap, int);
	str = ft_itoa(value);
	auto int len = ft_strlen(str);
	auto int padding = 0;
	auto int sign = 0;
	if (value < 0 || flags->padding == '+' || flags->padding == ' ')
		sign = 1;
	if (flags->width > len + sign)
		padding = flags->width - len - sign;
	if (flags->precision > len)
		padding += flags->precision - len;
	if (flags->precision > len)
		print_padding(flags->precision - len, '0', op);
	if (flags->padding != '-' && flags->padding != '0')
		print_padding(padding, ' ', op);
	print_sign(flags);
	if (flags->padding == '0')
		print_padding(padding, '0', op);
	print_integer_str(str, op);
	if (flags->padding == '-')
		print_padding(padding, ' ', op);
	free(str);
}
