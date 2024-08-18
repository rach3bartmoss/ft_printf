/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:28:42 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 16:15:21 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	unsigned_calc_padding(t_flags *flags, int len, int value)
{
	int	padding;

	padding = 0;
	if (flags->width >= len && value == 0 && flags->precision == 0)
		padding = flags->width - len + 1;
	else
		padding = flags->width - len;
	return (padding);
}
