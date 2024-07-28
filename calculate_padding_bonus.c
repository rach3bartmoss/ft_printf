/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_padding_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:38:50 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/28 16:46:29 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	calculate_padding_bonus(t_flags *flags, int len, int sign)
{
	int	total_len;

	total_len = len;
	if (flags->precision > len)
		total_len = flags->precision;
	if (sign)
		total_len++;
	if (flags->width > total_len)
		return (flags->width - total_len);
	else
		return (0);
}
