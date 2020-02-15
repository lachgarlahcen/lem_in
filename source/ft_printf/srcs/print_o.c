/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:44:47 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

char		*to_octal(unsigned long long int d)
{
	t_varo	o;

	o.i = 0;
	if (d == 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	else
	{
		o.p = ft_strnew(20);
		while (d != 0)
		{
			o.p[o.i++] += (d % 8) + 48;
			d /= 8;
		}
		o.j = o.i - 1;
		o.p[o.i] = '\0';
		o.i = 0;
		while (o.i < o.j)
		{
			o.tmp = o.p[o.j];
			o.p[o.j--] = o.p[o.i];
			o.p[o.i++] = o.tmp;
		}
	}
	return (o.p);
}

static void	lkk(t_flags f, char **c)
{
	if (f.tag && *c[0] != '0')
		*c = freesetjoin('0', 1, *c);
	if (f.w > (int)ft_strlen(*c))
	{
		if (f.zero && f.pre == -1 && f.m == 0)
			*c = freesetjoin('0', f.w - ft_strlen(*c), *c);
		if (!(f.zero && f.pre == -1) && f.m == 0)
			*c = freesetjoin(' ', f.w - ft_strlen(*c), *c);
		else if (f.m == 1)
			*c = frsetjoin(*c, f.w - ft_strlen(*c), ' ');
	}
}

int			print_o(va_list str, t_flags f)
{
	unsigned long long int	i;
	char					*c;
	int						len;

	i = va_arg(str, unsigned long long int);
	if (f.l == 1 || f.j || f.z)
		c = to_octal((unsigned long int)i);
	else if (f.l == 2)
		c = to_octal((unsigned long long int)i);
	else if (f.h == 1)
		c = to_octal((unsigned short int)i);
	else if (f.h == 2)
		c = to_octal((unsigned char)i);
	else
		c = to_octal((unsigned int)i);
	len = ft_strlen(c);
	if (f.pre - len >= 0)
		c = freesetjoin('0', f.pre - len, c);
	if (c[0] == '0' && f.pre == 0)
		c[0] = '\0';
	lkk(f, &c);
	len = ft_strlen(c);
	write(1, c, len);
	free(c);
	return (len);
}
