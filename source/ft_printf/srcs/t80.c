/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t80.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 01:29:14 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/ft_printf.h"

static char	*calmanti(int *str)
{
	int		i;
	char	*s;
	char	*t;
	int		j;

	i = 81;
	s = ft_memset(ft_strnew(100), 48, 100);
	s[99] = '\0';
	while (--i > 16)
	{
		if (str[i] == 1)
		{
			j = ft_strlen(power("5", i - 16));
			if (j < i - 16)
			{
				t = ft_memset(ft_strnew(i - 16 - j), 48, i - 16 - j);
				add(s, ft_strjoin(t, power("5", i - 16)));
				free(t);
			}
			else
				add(s, power("5", i - 16));
		}
	}
	return (s);
}

static void	init(int *i, t_vars *t, int *str)
{
	t->t = power("2", *i);
	t->tmp2 = calmanti(str);
	t->s = multp(t->t, t->tmp2);
	t->tmp = ft_memset(ft_strnew(1), '0', 1);
	t->l = ft_strlen(t->s);
}

static char	*low(int i, int *str, t_vars t)
{
	i = -i;
	t.t = power("5", i);
	t.l = ft_strlen(t.t);
	t.t = ft_strjoin(ft_memset(ft_strnew(i - t.l), '0', i - t.l), t.t);
	t.tmp2 = calmanti(str);
	t.s = multp(t.t, t.tmp2);
	t.l = ft_strlen(t.t);
	i = ft_strlen(t.tmp2);
	t.tmp = ft_memset(ft_strnew(t.l + i), 48, t.l + i);
	t.s = ad(t.s, t.tmp, 1);
	i = ft_strlen(t.s);
	if (str[16])
		t.s = add(t.s, t.t);
	free(t.t);
	t.l = ft_strlen(t.s);
	t.tmp = ft_memset(ft_strnew(1), '0', 1);
	if (t.l - i > 0)
		t.tmp = ft_strsub(t.s, 0, t.l - i);
	t.s += t.l - i;
	t.t = ft_strjoin(t.tmp, ".");
	free(t.tmp);
	t.tmp = ft_strjoin(t.t, t.s);
	free(t.t);
	free(t.s);
	return (t.tmp);
}

static char	*algo(int i, int *str)
{
	t_vars t;

	init(&i, &t, str);
	if (i < 0)
		return (low(i, str, t));
	i = ft_strlen(t.tmp2);
	if (t.l > i)
	{
		t.tmp = ft_strsub(t.s, 0, t.l - i);
		t.s += t.l - i;
	}
	if (str[16])
	{
		if (t.t[0] == '2' && t.tmp[0] == '1' && !t.t[1] && !t.tmp[1])
			t.t = "3";
		else
			t.t = ad(t.t, t.tmp, 1);
	}
	else
		t.t = t.tmp;
	free(t.tmp);
	t.tmp = ft_strjoin(t.t, ".");
	t.t = ft_strjoin(t.tmp, t.s);
	free(t.tmp);
	return (t.t);
}

char		*ld(long double v)
{
	int			str[80];
	char		*s;
	t_doublee	var;

	var.d = v;
	str[0] = var.u_fieldd.sign;
	bbinaire(var.u_fieldd.exponent, 14, str, 1);
	bbinaire(var.u_fieldd.m2, 31, str, 16);
	bbinaire(var.u_fieldd.m1, 31, str, 48);
	if (limi(&s, str) == 1)
		return (s);
	if (!str[0])
		return (algo(calcexxpo(str), str));
	else
		return (ft_strjoin("-", algo(calcexxpo(str), str)));
}
