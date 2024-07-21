/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:40:33 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/22 00:07:58 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	print_sign(t_flags *flags, int value, t_list *op)
{
	if (value < 0)
		ft_putchar('-');
	else if (flags->padding == '+')
		ft_putchar('+');
	else if (flags->padding == ' ')
		ft_putchar(' ');
	else
		return ;
	op->count++;
}

static void	print_integer_str(const char *str, t_list *op)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i++]);
		op->count++;
	}
}

static int	calculate_padding(t_flags *flags, int len, int sign)
{
	int	total_len;

	total_len = len;
	if (flags->precision > len)
		total_len = flags->precision;
	if (sign)
		total_len++;
	if (flags->width > total_len)
		return (flags->width - total_len);
	else
		return (0);
}

static void	handle_padding(t_flags *flags, int padding, int value, t_list *op)
{
	if (flags->zero_pad && !flags->left_align)
	{
		print_sign(flags, value, op);
		print_padding(padding, '0', op);
	}
	else if (!flags->left_align)
	{
		print_padding(padding, ' ', op);
		print_sign(flags, value, op);
	}
	else
		print_sign(flags, value, op);
}

void	print_int(t_flags *flags, t_list *op)
{
	char	*str;
	int		value;
	int		len;
	int		padding;
	int		sign;

	value = va_arg(op->ap, int);
	if (value < 0)
		str = ft_itoa(-value);
	else
		str = ft_itoa(value);
	if (!str)
		return ;
	len = ft_strlen(str);
	sign = 0;
	if (value < 0 || flags->padding == '+' || flags->padding == ' ')
		sign = 1;
	padding = calculate_padding(flags, len, sign);
	handle_padding(flags, padding, value, op);
	if (flags->precision > len)
		print_padding(flags->precision - len, '0', op);
	print_integer_str(str, op);
	if (flags->left_align == '-')
		print_padding(padding, ' ', op);
	free(str);
}
