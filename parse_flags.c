/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:49:46 by dopereir          #+#    #+#             */
/*   Updated: 2024/07/15 20:10:51 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <ctype.h>
#include <stdlib.h>

void	parse_padding(t_flags *flags, const char *format, size_t *i)
{
	while (ft_strchr("+-0# ", format[*i]))
	{
		flags->padding = format[*i];
		(*i)++;
	}
}

void	parse_number(int *field, const char *format, size_t *i)
{
	if (ft_isdigit(format[*i]))
	{
		*field = ft_atoi(&format[*i]);
		while (ft_isdigit(format[*i]))
			(*i)++;
	}
}

void	parse_length(t_flags *flags, const char *format, size_t *i)
{
	if (ft_strchr("hljz", format[*i]))
	{
		if ((format[*i] == 'h' && format[*i + 1] == 'h')
			|| (format[*i] == 'l' && format[*i + 1] == 'l'))
		{
			if (format[*i] == 'h')
				flags->len_flags = "hh";
			else
				flags->len_flags = "ll";
			(*i)++;
		}
		else
		{
			if (format[*i] == 'h')
				flags->len_flags = "h";
			else if (format[*i] == 'l')
				flags->len_flags = "l";
			else if (format[*i] == 'j')
				flags->len_flags = "j";
			else if (format[*i] == 'z')
				flags->len_flags = "z";
		}
		(*i)++;
	}
}

void	parse_flags(t_flags *flags, const char *format, size_t *i)
{
	parse_padding(flags, format, i);
	parse_number(&(flags->width), format, i);
	if (format[*i] == '.')
	{
		(*i)++;
		parse_number(&(flags->precision), format, i);
	}
	parse_length(flags, format, i);
	if (ft_strchr("sSpdDioOuUxXcC%", format[*i]))
	{
		flags->specifier = format[*i];
		(*i)++;
	}
}
/*void	parse_flags(t_flags *flags, const char *format, size_t *i)
{
	flags->width = 0;
	flags->precision = -1;
	flags->len_flags = NULL;
	flags->conversion = '\0';
	flags->padding = '\0';
	flags->specifier = '\0';
	(*i)++;
	while (format[*i] == '+' || format[*i] == '-' || format[*i] == '0'
		|| format[*i] == ' ' || format[*i] == '#')
	{
		flags->padding = format[*i];
		(*i)++;
	}
	if (isdigit(format[*i]))
	{
		flags->width = atoi(&format[*i]);
		while (isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		flags->precision = atoi(&format[*i]);
		while (isdigit(format[*i]))
			(*i)++;
	}
	if (format[*i] == 'h' || format[*i] == 'l'
		|| format[*i] == 'j' || format[*i] == 'z')
	{
		if (format[*i] == 'h' && format[*i + 1] == 'h')
		{
			flags->len_flags = "hh";
			(*i)++;
		}
		else if (format[*i] == 'l' && format[*i + 1] == 'l')
		{
			flags->len_flags = "ll";
			(*i)++;
		}
		else
			flags->len_flags = (char []){format[*i], '\0'};
		(*i)++;
	}
	if (strchr("sSpdDioOuUxXcC", format[*i]))
	{
		flags->conversion = format[*i];
		(*i)++;
	}
}*/
