/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_padding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:51:09 by dopereir          #+#    #+#             */
/*   Updated: 2024/06/28 22:42:20 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	print_padding(int length, char pad_char, t_list *op)
{
	auto int i = 0;
	while (i < length)
	{
		ft_putchar(pad_char);
		i++;
		op->count++;
	}
}
