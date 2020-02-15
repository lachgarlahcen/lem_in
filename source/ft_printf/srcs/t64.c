/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t64.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 11:14:47 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../headers/ft_printf.h"

static int	calcexpo(int *str)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (++i < 12)
		if (str[12 - i] == 1)
			s += ft_atoi(power("2", i - 1));
	return (s - 1023);
}

static char	*calmanti(int *str, int i)
{
	char	*s;
	char	*t;
	char	*tmp;
	int		j;

	s = ft_memset(ft_strnew(100), 48, 100);
	s[99] = '\0';
	while (--i > 11)
	{
		tmp = power("5", i - 11);
		if (str[i] == 1)
		{
			j = ft_strlen(tmp);
			if (j < i - 11)
			{
				t = ft_memset(ft_strnew(i - 11 - j), 48, i - 11 - j);
				add(s, ft_strjoin(t, tmp));
				free(t);
			}
			else
				add(s, tmp);
		}
	}
	return (s);
}

static char	*algcd(t_chralgo *k, int *i, int *l, char **tmp2)
{
	*i = -(*i);
	k->t = power("5", *i);
	*l = ft_strlen(k->t);
	k->t = ft_strjoin(ft_memset(ft_strnew(*i - *l), '0', *i - *l), k->t);
	k->s = multp(k->t, *tmp2);
	*i = ft_strlen(*tmp2);
	k->tmp = ft_memset(ft_strnew(*l + *i), 48, *l + *i);
	k->s = ad(k->s, k->tmp, 1);
	*i = ft_strlen(k->s);
	k->s = add(k->s, k->t);
	k->tmp = ft_memset(ft_strnew(1), '0', 1);
	*l = ft_strlen(k->s);
	if (*l - *i > 0)
		k->tmp = ft_strsub(k->s, 0, *l - *i);
	k->s += *l - *i;
	k->t = ft_strjoin(k->tmp, ".");
	free(k->tmp);
	k->tmp = ft_strjoin(k->t, k->s);
	free(k->t);
	free(k->s);
	return (k->tmp);
}

static char	*algo(int i, int *str)
{
	t_chralgo	k;
	char		*tmp2;
	int			l;

	tmp2 = calmanti(str, 64);
	if (i < 0)
		return (algcd(&k, &i, &l, &tmp2));
	k.t = power("2", i);
	k.s = multp(k.t, tmp2);
	k.tmp = "0";
	l = ft_strlen(k.s);
	i = ft_strlen(tmp2);
	if (l > i)
	{
		k.tmp = ft_strsub(k.s, 0, l - i);
		k.s += l - i;
	}
	if (k.t[0] == '2' && k.tmp[0] == '1' && !k.t[1] && !k.tmp[1])
		k.t = "3";
	else
		k.t = ad(k.t, k.tmp, 1);
	k.tmp = ft_strjoin(k.t, ".");
	k.tmp = ft_strjoin(k.tmp, k.s);
	return (k.tmp);
}

char		*dbl(double *v)
{
	int			str[64];
	char		*s;
	t_double	var;

	var.d = *v;
	str[0] = var.u_field.sign;
	binaire(var.u_field.exponent, 10, str);
	binaire(var.u_field.m2, 19, str);
	binaire(var.u_field.m1, 31, str);
	if (lim(&s, str) == 1)
		return (s);
	if (!str[0])
		return (algo(calcexpo(str), str));
	else
		return (ft_strjoin("-", algo(calcexpo(str), str)));
}
