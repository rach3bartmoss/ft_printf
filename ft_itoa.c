/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:34:27 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/05 22:05:17 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <limits.h>

int	count_digits(int n)
{
	int	count;

	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (10);
	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*convert_to_string(long n)
{
	char	*str;

	auto int is_negative = n < 0, count = count_digits(n);
	str = malloc(count + is_negative + 1);
	if (!str)
		return (NULL);
	str[count + is_negative] = '\0';
	if (n == INT_MIN)
	{
		str[0] = '-';
		n = 2147483648;
	}
	else if (is_negative)
	{
		str[0] = '-';
		n = -n;
	}
	auto int i = count + is_negative - 1;
	while (i >= is_negative)
	{
		str[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(long n)
{
	return (convert_to_string(n));
}
