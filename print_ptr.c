/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:30:10 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/06 18:36:43 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>
#include <stdarg.h>

static void	ft_putstr(const char *str, t_list *op)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
		op->count++;
	}
}

void	print_ptr(t_flags *flags, t_list *op)
{
	void	*ptr;
	char	*str;
	int		len;
	int		padding;

	ptr = va_arg(op->ap, void *);
	str = ft_itoa_custombase((unsigned long)ptr, 16);
	len = ft_strlen(str) + 2;
	padding = 0;
	if (flags->width > len)
		padding = flags->width - len - 2;
	if (flags->padding != ' ' && padding > 0)
		print_padding(padding, ' ', op);
	if (!ptr)
	{
		ft_putstr("(nil)", op);
	}
	else
	{
		ft_putstr("0x", op);
		ft_putstr(str, op);
	}
	if (flags->padding == '-' && padding > 0)
		print_padding(padding, ' ', op);
	free(str);
}

/*int main()
{
    int x = 42;
    int *ptr = &x;

    // Test cases
    ft_printf("Pointer value: %p\n", ptr);
    ft_printf("Pointer value with width: %20p\n", ptr);
    ft_printf("Pointer value with left align: %-20p\n", ptr);
    ft_printf("Pointer value with precision: %.8p\n", ptr);

    return 0;
}*/
