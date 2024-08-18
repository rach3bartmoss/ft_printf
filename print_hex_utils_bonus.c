/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:15:56 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 16:15:47 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	prefix_len_func(t_flags *flags, int value)
{
	int	prefix_len;

	prefix_len = 0;
	if (flags->padding == '#' && value != 0)
		prefix_len = 2;
	return (prefix_len);
}

int	handle_flags_printhex(t_flags *flags, unsigned int value, int len,
	t_list *op)
{
	int		prefix_len;
	int		padding;
	char	*str_value;

	str_value = ft_itoa_custombase(value, 16);
	prefix_len = prefix_len_func(flags, value);
	if (flags->precision > len)
		len = flags->precision;
	padding = 0;
	if (flags->width >= len + prefix_len && value == 0 && flags->precision == 0)
		print_padding(flags->width - (len + prefix_len) + 1, ' ', op);
	else if (flags->width > len + prefix_len)
		padding = flags->width - (len + prefix_len);
	if (flags->left_align != '-')
	{
		if (flags->zero_pad == 1 && flags->precision < 0)
			print_padding(padding, '0', op);
		else
			print_padding(padding, ' ', op);
	}
	print_prefix_bonus(prefix_len, flags, op);
	if (flags->precision > (int)ft_strlen(str_value))
		print_padding(flags->precision - ft_strlen(str_value), '0', op);
	free(str_value);
	return (padding);
}
