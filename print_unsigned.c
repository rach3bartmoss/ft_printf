/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:37:07 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 15:29:14 by dopereir         ###   ########.fr       */
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
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision > len)
		len = flags->precision;
	padding = unsigned_calc_padding(flags, len, value);
	if (flags->left_align != '-' || flags->zero_pad == 1)
	{
		if (flags->zero_pad != 1 || flags->precision >= 0)
			print_padding(padding, ' ', op);
		else
			print_padding(padding, '0', op);
	}
	if (flags->precision > 0)
		print_padding(flags->precision - ft_strlen(str), '0', op);
	if (flags->precision != 0 || value != 0)
		ft_putstr(str, op);
	if (flags->left_align == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}

/*(SPACE) FLAGS IS NOT USED WITH %u, THE MIXED COMBINANTION OF ZERO PAD FLAGS
AND PRECISION IS NOT USED WUTH %u*/