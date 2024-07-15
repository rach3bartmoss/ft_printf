/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:17 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/13 00:55:20 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

void	print_string(t_flags *flags, t_list *op)
{
	char	*str;

	str = va_arg(op->ap, char *);
	if (!str)
		str = "(null)";
	auto int len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	auto int padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	if (padding > 0 && flags->padding != '-')
		print_padding(padding, ' ', op);
	auto int i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
		op->count++;
	}
	if (padding > 0 && flags->padding == '-')
		print_padding(padding, ' ', op);
}
