/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_padding_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:48:25 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/17 19:22:23 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_padding_bonus(t_flags *flags, int padding, size_t value,
	t_list *op)
{
	if (flags->zero_pad == 1 && flags->left_align != '-')
	{
		print_sign_bonus(flags, value, op);
		print_padding(padding, '0', op);
	}
	else if (!flags->left_align)
	{
		print_padding(padding, ' ', op);
		print_sign_bonus(flags, value, op);
	}
	else
	{
		print_sign_bonus(flags, value, op);
	}
}
