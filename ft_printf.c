/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:50:25 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/13 01:55:47 by dopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

static void	handle_specifier(t_flags *flags, t_list *op)
{
	if (flags->specifier == 'd' || flags->specifier == 'i')
		print_int(flags, op);
	else if (flags->specifier == 'c')
		print_char(flags, op);
	else if (flags->specifier == 's')
		print_string(flags, op);
	else if (flags->specifier == 'f')
		print_float(flags, op);
	else if (flags->specifier == 'p')
		print_ptr(flags, op);
	else if (flags->specifier == 'x' || flags->specifier == 'X')
		print_hex(flags, op);
	else if (flags->specifier == 'u')
		print_unsigned(flags, op);
	else if (flags->specifier == 'o')
		print_octal(flags, op);
}

static void	print_char_local(char c, t_list *op)
{
	ft_putchar(c);
	op->count++;
}

static void	parse_and_print(const char *format, t_list *op)
{
	size_t	start_i;
	t_flags	flags;

	flags.width = 0;
	flags.precision = -1;
	flags.len_flags = 0;
	flags.specifier = 0;
	flags.padding = 0;
	start_i = op->i;
	parse_flags(&flags, format, &op->i);
	handle_specifier(&flags, op);
	op->i = op->i - start_i;
}

int	ft_printf(const char *format, ...)
{
	t_list	op;

	op.i = 0;
	op.count = 0;
	va_start(op.ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == '%')
				print_char_local('%', &op);
			format++;
			parse_and_print(format, &op);
			format += op.i - 1;
		}
		else
			print_char_local(*format, &op);
		format++;
	}
	va_end(op.ap);
	return (op.count);
}
