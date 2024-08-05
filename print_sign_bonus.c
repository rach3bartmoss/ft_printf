/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:23:54 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/05 22:11:15 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>

void	print_sign_bonus(t_flags *flags, int value, t_list *op)
{
	if (value == INT_MIN)
		return ;
	else if (value < 0 && value != INT_MIN)
		ft_putchar('-');
	else if (flags->padding == '+')
		ft_putchar('+');
	else if (flags->padding == ' ')
		ft_putchar(' ');
	else
		return ;
	op->count++;
}
