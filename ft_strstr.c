/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 23:37:15 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/13 23:41:28 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strstr(const char *needle, const char *hay)
{
	if (!hay)
		return (0);
	while (*needle)
	{
		if (!ft_strchr(hay, *needle))
			return (0);
		needle++;
	}
	return (1);
}
