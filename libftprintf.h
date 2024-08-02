/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <dopereir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:05:50 by dopereir          #+#    #+#             */
/*   Updated: 2024/08/02 01:31:40 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stddef.h>

typedef struct s_flags
{
	int		width; // ex = %10s "print min of 10 char from str"
	int		precision; // ".precision" ex: input = 1234 %.3d = "123"
	char	specifier; // "sSpdDioOuUxXcC" %d, %i, %s etc..-
	char	padding; // "+(SPACE)#"
	char	left_align; // for '-' flag
	int		zero_pad; // for '0' flags
}		t_flags;

typedef struct s_list
{
	va_list	ap; // takes the arguments passed as parameters
	size_t	i; // keep the indexes through the operations
	size_t	count; // keep count of the number of characters printed
}		t_list;

// Standard functions
int		ft_atoi(const char *str); //OK
char	*ft_strchr(const char *s, int c); //OK
int		ft_isdigit(int i); //OK
char	*ft_itoa(int n); //OK
size_t	ft_strlen(const char *str); //OK
void	ft_putchar(char c); //OK

// Helper functions
void	print_padding(int length, char pad_char, t_list *op);
char	*ft_itoa_custombase(unsigned long value, int base);
void	parse_flags(t_flags *flags, const char *format, size_t *i);

//Bonus functions
void	print_sign_bonus(t_flags *flags, int value, t_list *op);
void	print_integer_str_bonus(const char *str, t_list *op);
int		calculate_padding_bonus(t_flags *flags, int len, int sign);
void	handle_padding_bonus(t_flags *flags, int padding, int value,
			t_list *op);
int		print_prefix_bonus(int prefix_len, t_flags *flags, t_list *op);

// Main functions
void	print_int(t_flags *flags, t_list *op);
void	print_char(t_flags *flags, t_list *op);
void	print_string(t_flags *flags, t_list *op);
void	print_ptr(t_flags *flags, t_list *op);
void	print_hex(t_flags *flags, t_list *op);
void	print_unsigned(t_flags *flags, t_list *op);
int		ft_printf(const char *format, ...);
#endif
