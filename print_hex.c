/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:29:52 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 15:22:22 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

static void	ft_putstr_hexfunc(const char *str, t_list *op, t_flags *flags)
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

void	print_hex(t_flags *flags, t_list *op)
{
	char			*str;
	unsigned int	value;
	int				len;
	int				padding;

	value = va_arg(op->ap, unsigned int);
	str = ft_itoa_custombase(value, 16);
	len = ft_strlen(str);
	padding = handle_flags_printhex(flags, value, len, op);
	if (flags->precision != 0 || value != 0)
		ft_putstr_hexfunc(str, op, flags);
	if (flags->left_align == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}
