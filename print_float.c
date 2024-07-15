/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:30:40 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/04 22:35:18 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static void	print_fraction(double frac_part, int precision, t_list *op)
{
	while (precision-- > 0)
	{
		frac_part *= 10;
		auto int digit = (int)frac_part;
		ft_putchar('0' + digit);
		op->count++;
		frac_part -= digit;
	}
}

static void	print_int_part(long long int_part, t_list *op)
{
	char	*int_str;

	int_str = ft_itoa(int_part);
	auto int int_len = ft_strlen(int_str);
	auto int i = 0;
	while (i < int_len)
	{
		ft_putchar(int_str[i]);
		i++;
		op->count++;
	}
	free(int_str);
}

static void	sign_and_padding(double value, t_flags *flags, int padding,
		t_list *op)
{
	if (value < 0)
		ft_putchar('-');
	else if (flags->padding == '+')
		ft_putchar('+');
	else if (flags->padding == ' ')
		ft_putchar(' ');
	if (flags->padding == '0' && padding > 0)
		print_padding(padding, '0', op);
}

void	print_float(t_flags *flags, t_list *op)
{
	auto double value = va_arg(op->ap, double);
	auto long long int_part = (long long)value;
	auto double frac_part = value - int_part;
	auto int sign = get_sign(value, flags);
	if (value < 0)
		value = -value;
	auto int int_len = ft_strlen(ft_itoa(int_part));
	auto int precision = get_precision(flags);
	auto int frac_len = precision;
	auto int total_len = int_len + frac_len + 1 + sign;
	auto int padding = get_padding(total_len, flags);
	if (flags->padding != '-' && flags->padding != '0' && padding > 0)
		print_padding(padding, ' ', op);
	sign_and_padding(value, flags, padding, op);
	print_int_part(int_part, op);
	ft_putchar('.');
	op->count++;
	print_fraction(frac_part, precision, op);
	if (flags->padding == '-' && padding > 0)
		print_padding(padding, ' ', op);
}
