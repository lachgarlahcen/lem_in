/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:38:46 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

int		print_p(va_list str, t_flags f)
{
	char	*c;
	int		i;

	c = to_hexa((long int)va_arg(str, char *), 87, f);
	i = ft_strlen(c);
	if (f.pre > i)
		c = freesetjoin('0', f.pre - i, c);
	if (f.w > (int)ft_strlen(c) + 2)
	{
		if (f.zero && f.pre == -1 && f.m == 0)
			c = freesetjoin('0', f.w - 2 - ft_strlen(c), c);
		c = freejoin("0x", c);
		if (!(f.zero && f.pre == -1) && f.m == 0)
			c = freesetjoin(' ', f.w - ft_strlen(c), c);
		else if (f.m == 1)
			c = frsetjoin(c, f.w - ft_strlen(c), ' ');
	}
	else
		c = freejoin("0x", c);
	write(1, c, ft_strlen(c));
	i = ft_strlen(c);
	free(c);
	return (i);
}
