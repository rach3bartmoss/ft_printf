/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_padding_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:48:25 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/28 17:06:05 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	handle_padding_bonus(t_flags *flags, int padding, int value, t_list *op)
{
	if (flags->zero_pad && !flags->left_align)
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
		print_sign_bonus(flags, value, op);
}
