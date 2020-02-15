/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:00:05 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static int	cond2(va_list str, char **c, t_flags f)
{
	if (f.w <= 1)
	{
		f.w = 1;
		*c = ft_strnew(f.w);
		*c[0] = va_arg(str, int);
	}
	write(1, *c, f.w);
	free(*c);
	if (f.w > 0)
		return (f.w);
	return (1);
}

int			print_c(va_list str, t_flags f)
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
			c[i++] = va_arg(str, int);
			while (i < f.w)
				c[i++] = ' ';
		}
		else if (!f.zero)
		{
			while (i < f.w - 1)
				c[i++] = ' ';
			c[i] = va_arg(str, int);
		}
		else
			c[f.w - 1] = va_arg(str, int);
	}
	return (cond2(str, &c, f));
}
