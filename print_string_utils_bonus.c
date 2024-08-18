/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 15:25:06 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/18 16:15:56 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	adjust_len(t_flags *flags, int len, int was_null)
{
	if (was_null)
	{
		if (flags->precision >= 0 && flags->precision < 6)
			return (0);
		if (flags->precision >= 6)
			return (6);
	}
	else if (flags->precision >= 0 && flags->precision < len)
		return (flags->precision);
	return (len);
}
