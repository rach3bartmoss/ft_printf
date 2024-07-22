/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:29:52 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/22 21:29:23 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	ft_putstr(const char *str, t_list *op, t_flags *flags)
{
	while (*str)
	{
		if (flags->specifier == 'X' && *str >= 'a' && *str <= 'z')
			ft_putchar(*str - 32);
		else
		{
			if (flags->specifier == 'x' && *str >= 'A' && *str <= 'Z')
				ft_putchar(*str + 32);
			else
				ft_putchar(*str);
		}
		str++;
		op->count++;
	}
}

static int	print_prefix(int prefix_len, t_flags *flags, t_list *op)
{
	if (flags->padding == '#' && prefix_len > 0)
	{
		if (flags->specifier == 'X')
		{
			ft_putchar('0');
			ft_putchar('X');
			op->count += 2;
			return (2);
		}
		else if (flags->specifier == 'x')
		{
			ft_putchar('0');
			ft_putchar('x');
			op->count += 2;
			return (2);
		}
	}
	return (0);
}

static int	handle_flags(t_flags *flags, unsigned int value, int len,
		t_list *op)
{
	int	prefix_len;
	int	padding;

	prefix_len = 0;
	if (flags->padding == '#' && value != 0)
		prefix_len = 2;
	if (flags->precision >= 0 && flags->precision > len)
		len = flags->precision;
	padding = 0;
	if (flags->width > len + prefix_len)
		padding = flags->width - (len + prefix_len);
	if (flags->padding != '-' && flags->padding != '0' && padding > 0)
		print_padding(padding, ' ', op);
	print_prefix(prefix_len, flags, op);
	if (flags->precision > 0)
		print_padding(flags->precision - len, '0', op);
	if (flags->padding == '0' && padding > 0 && flags->precision < 0)
		print_padding(padding, '0', op);
	return (padding);
}

void	print_hex(t_flags *flags, t_list *op)
{
	char			*str;
	unsigned int	value;
	int				len;
	int				padding;

	value = va_arg(op->ap, unsigned int);
	str = ft_itoa_custombase(value, 16);
	if (!str)
		return ;
	len = ft_strlen(str);
	padding = handle_flags(flags, value, len, op);
	ft_putstr(str, op, flags);
	if (flags->padding == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}
