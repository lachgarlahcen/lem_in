/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:04:35 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*to_bin(unsigned long long int d)
{
	int		i;
	int		j;
	char	*p;
	char	tmp;

	p = ft_strnew(100);
	i = 0;
	while (d != 0)
	{
		p[i++] += (d % 2) + 48;
		d /= 2;
	}
	j = i - 1;
	p[i] = '\0';
	i = 0;
	while (i < j)
	{
		tmp = p[j];
		p[j--] = p[i];
		p[i++] = tmp;
	}
	return (p);
}

static void	lkk(t_flags f, char **c)
{
	if (f.tag)
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

int			print_b(va_list str, t_flags f)
{
	unsigned long long int	i;
	char					*c;
	int						len;

	i = va_arg(str, unsigned long long int);
	if (f.l == 1)
		c = to_bin((unsigned long int)i);
	else if (f.l == 2)
		c = to_bin((unsigned long long int)i);
	else if (f.h == 1)
		c = to_bin((unsigned short int)i);
	else if (f.h == 2)
		c = to_bin((unsigned char)i);
	else
		c = to_bin((unsigned int)i);
	len = ft_strlen(c);
	if (f.pre - len >= 0)
		c = freesetjoin('0', f.pre - len, c);
	lkk(f, &c);
	len = ft_strlen(c);
	write(1, c, len);
	free(c);
	return (len);
}
