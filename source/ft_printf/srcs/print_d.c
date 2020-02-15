/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 02:58:31 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static	char	*fjoin(char *a, char *b)
{
	char *tmp;

	tmp = ft_strjoin(a, b);
	free(b - 1);
	return (tmp);
}

static void		print_d_cond(t_flags f, char **c, int i, int j)
{
	if (f.zero && f.pre == -1 && f.m == 0)
		*c = freesetjoin('0', f.w - i - j - ft_strlen(*c), *c);
	if (i && f.p)
		*c = freejoin("+", *c);
	else if (i && f.spc)
		*c = freejoin(" ", *c);
	else if (j)
		*c = freejoin("-", *c);
	if (!(f.zero && f.pre == -1) && f.m == 0)
		*c = freesetjoin(' ', f.w - ft_strlen(*c), *c);
	else if (f.m == 1)
		*c = frsetjoin(*c, f.w - ft_strlen(*c), ' ');
}

static int		print_d_d(char *c, t_flags f, int j)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(c);
	if ((f.p == 1 && j == 0) || (f.spc == 1 && j == 0))
		i = 1;
	if (f.pre - len >= 0)
		c = freesetjoin('0', f.pre - len, c);
	if (f.w > (int)ft_strlen(c))
		print_d_cond(f, &c, i, j);
	else if (i && f.p)
		c = freejoin("+", c);
	else if (i && f.spc)
		c = freejoin(" ", c);
	else if (j)
		c = freejoin("-", c);
	if (c[0] == '-' && c[1] == '-')
		c = fjoin("", c + 1);
	write(1, c, ft_strlen(c));
	i = ft_strlen(c);
	free(c);
	return (i);
}

int				print_d(va_list str, t_flags f)
{
	long long int	i;
	char			*c;
	int				j;

	i = va_arg(str, long long int);
	j = 0;
	if (f.l == 1)
		i = (long int)i;
	else if (f.l == 2)
		i = (long long int)i;
	else if (f.h == 1)
		i = (short int)i;
	else if (f.h == 2)
		i = (char)i;
	else if (f.j || f.z)
		i = (intmax_t)i;
	else
		i = (int)i;
	if (i < 0)
		j = 1;
	c = ft_iitoa(i);
	if (c[0] == '0' && f.pre == 0)
		c[0] = '\0';
	return (print_d_d(c, f, j));
}
