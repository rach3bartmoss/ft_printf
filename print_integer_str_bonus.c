/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_str_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:30:35 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/08 18:26:41 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	print_integer_str_bonus(const char *str, t_list *op, t_flags *flags)
{
	int	i;
	int	j;
	int	value;
	int	len;

	value = ft_atoi(str);
	len = ft_strlen(str);
	i = 0;
	if (0 > value)
	{
		ft_putchar('-');
		op->count++;
		if (flags->precision >= len)
			print_padding(flags->precision - len + 1, '0', op);
		j = 1;
		while (str[j])
		{
			ft_putchar(str[j++]);
			op->count++;
		}
	}
	else
	{
		while (str[i] != '\0')
		{
			ft_putchar(str[i++]);
			op->count++;
		}
	}
}
