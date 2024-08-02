/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:17 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/29 00:57:44 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

void	print_string(t_flags *flags, t_list *op)
{
	char	*str;
	int		len;
	int		padding;
	int		i;

	str = va_arg(op->ap, char *);
	if (!str)
		str = "(nil)";
	len = ft_strlen(str);
	if (flags->precision >= 0 && flags->precision < len)
		len = flags->precision;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len;
	if (flags->left_align != '-')
		print_padding(padding, ' ', op);
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
		op->count++;
	}
	if (flags->left_align == '-')
		print_padding(padding, ' ', op);
}
