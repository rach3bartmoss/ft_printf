/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopereir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:45:19 by dopereir          #+#    #+#             */
/*   Updated: 2024/06/28 22:37:50 by rache            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == c)
		return ((char *)s);
	else
		return (NULL);
}
/*int	main()
{
	const char	test[] = "RACHE BARTMOSS";
	char	*c;

	c = ft_strchr(test, 'S');

	if (c != NULL)
		printf("Character found at position %ld\n", c - test + 1);
	else
		printf("Character not found in the string.\n");
	return (0);
}*/
