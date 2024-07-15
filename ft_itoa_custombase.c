/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_custombase.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 16:20:32 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/04 21:10:35 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

char	*ft_itoa_custombase(unsigned long value, int base)
{
	char	*str;
	char	*digits;

	digits = "0123456789abcdef";
	auto int len = 0;
	auto unsigned long tmp = value;
	while (tmp != 0)
	{
		tmp /= base;
		len++;
	}
	if (value == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = digits[value % base];
		value /= base;
	}
	return (str);
}
