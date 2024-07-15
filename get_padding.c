/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rache <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:07:01 by rache             #+#    #+#             */
/*   Updated: 2024/06/28 22:38:26 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

int	get_padding(int total_len, t_flags *flags)
{
	if (flags->width > total_len)
		return (flags->width - total_len);
	return (0);
}
