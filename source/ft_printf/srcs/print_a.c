/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 01:10:42 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static int	cd(char str1, char **c, t_flags f)
{
	if (f.w <= 1)
	{
		f.w = 1;
		*c = ft_strnew(f.w);
		*c[0] = str1;
	}
	write(1, *c, f.w);
	free(*c);
	if (f.w > 0)
		return (f.w);
	return (1);
}

int			print_a(const char *str1, t_flags f)
{
	char	*c;
	int		i;

	i = 0;
	if (f.w > 1)
	{
		c = ft_strnew(f.w);
		c = ft_memset(c, '0', f.w);
		if (f.m)
		{
			c[i++] = *str1;
			while (i < f.w)
				c[i++] = ' ';
		}
		else if (!f.zero)
		{
			while (i < f.w - 1)
				c[i++] = ' ';
			c[i] = *str1;
		}
		else
			c[f.w - 1] = *str1;
	}
	return (cd(*str1, &c, f));
}
