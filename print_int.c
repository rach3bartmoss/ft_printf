/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:40:33 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/02 01:31:58 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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
	padding = calculate_padding_bonus(flags, len, sign);
	handle_padding_bonus(flags, padding, value, op);
	if (flags->precision > len)
		print_padding(flags->precision - len, '0', op);
	print_integer_str_bonus(str, op);
	if (flags->left_align == '-')
		print_padding(padding, ' ', op);
	free(str);
}
