/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:11:56 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 16:14:37 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	calculate_padding_bonus(int value, t_flags *flags, int len, int sign)
{
	int	total_len;

	total_len = len;
	if (flags->precision > len)
		total_len = flags->precision;
	if (sign || flags->padding == ' ')
		total_len++;
	if (flags->width >= total_len)
	{
		if (flags->precision == 0 || value == INT_MIN)
			return (flags->width - total_len + 1);
		else
			return (flags->width - total_len);
	}
	else
		return (0);
}

static void	edge_cases(t_flags *flags, int padding, int value, t_list *op)
{
	if (flags->zero_pad == 1 && flags->precision == 0 && value != 0)
	{
		print_padding(padding - 1, ' ', op);
		print_sign_bonus(flags, value, op);
	}
	else
	{
		print_padding(padding, ' ', op);
		print_sign_bonus(flags, value, op);
	}
}

void	handle_padding_bonus(t_flags *flags, int padding, size_t value,
	t_list *op)
{
	if (flags->zero_pad == 1 && flags->left_align != '-'
		&& flags->precision < 0)
	{
		print_sign_bonus(flags, value, op);
		print_padding(padding, '0', op);
	}
	else if (!flags->left_align)
	{
		if (value == 0 && flags->precision == 0 && flags->width > 0)
			print_padding(flags->width, ' ', op);
		else if (flags->width > 0 && padding > 0)
		{
			edge_cases(flags, padding, value, op);
		}
		else
			print_sign_bonus(flags, value, op);
	}
	else
		print_sign_bonus(flags, value, op);
}

void	negative_case(t_list *op, const char *str, t_flags *flags)
{
	int	j;

	if (flags->zero_pad != 1)
	{
		ft_putchar('-');
		op->count++;
	}
	if (flags->precision >= (int)ft_strlen(str))
		print_padding(flags->precision - ft_strlen(str) + 1, '0', op);
	j = 1;
	while (str[j])
	{
		ft_putchar(str[j++]);
		op->count++;
	}
}

void	print_integer_str(const char *str, t_list *op, t_flags *flags)
{
	int	i;
	int	value;

	value = ft_atoi(str);
	i = 0;
	if (value < 0)
		i = 1;
	if (0 > value)
		negative_case(op, str, flags);
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i++]);
			op->count++;
		}
	}
}
