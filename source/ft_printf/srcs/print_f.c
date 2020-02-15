/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 22:16:33 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/12 04:32:48 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static char	*pls(char *s, int i)
{
	while (i < 0)
	{
		s = freejoin("0", s);
		i++;
	}
	if (s[i] == '.')
		i--;
	if (s[i] == '9')
	{
		s[i] = '0';
		return (pls(s, i - 1));
	}
	else
		s[i]++;
	return (s);
}

static void	condaa(t_flags *f, char *t, int i)
{
	if (!f->zero)
		while (f->w-- > i)
			write(1, " ", 1);
	if (t[0] != '-' && f->p)
		write(1, "+", 1);
	else if (t[0] != '-' && f->spc && !f->w)
		write(1, " ", 1);
	if (t[0] != '-' && f->spc)
		f->w--;
	if (f->zero && !f->m)
	{
		if (t[0] == '-')
		{
			write(1, "-", 1);
			i--;
			f->w--;
			t++;
		}
		while (f->w-- > i)
			write(1, "0", 1);
	}
	write(1, t, i);
}

static void	conda(t_flags *f, char *t, int *i, int *w)
{
	if (f->w > *i)
	{
		*w = f->w;
		if (f->p && t[0] != '-')
			f->w--;
		if (!f->m)
			condaa(f, t, *i);
		else
			less(f, t, i);
	}
	else
	{
		if (t[0] != '-' && f->p)
			write(1, "+", 1);
		else if (t[0] != '-' && f->spc)
			write(1, " ", 1);
		write(1, t, *i);
	}
}

static void	condb(t_flags *f, int *i, char **t)
{
	int		len;

	if (f->pre > -1)
		*i += f->pre;
	else
		*i += 6;
	len = ft_strlen(*t);
	if (*i > len)
		*t = frsetjoin(*t, *i - len + 1, '0');
	else if (*i < len)
	{
		if (t[0][*i] > '4')
			*t = addd(*t, "1", len - *i + 1, i);
		else if ((f->pre == 0 && ((t[0][*i - 1] - 48) % 2 == 1
					|| t[0][*i - 1] == 0 || t[0][*i + 2] > '0'
					|| t[0][*i + 3] > '0') && t[0][*i + 1] > '4')
				|| ((t[0][*i - 1] - 48) % 2 == 0 && t[0][*i + 1] > '5'
					&& f->pre == 0)
				|| (check_round(t[0], *i + 1) && f->pre == 0))
			*t = addd(*t, "1", len - *i + 1, i);
	}
	else if (*i < len && t[0][*i + 1] > '4')
		*t = pls(*t, *i);
}

int			print_f(va_list str, t_flags f)
{
	t_vardb	dob;

	dob.i = 0;
	dob.w = 0;
	dob.t = cast(f, str);
	if (dob.t[1] >= 'a' && dob.t[1] < 'z')
		return (print_lim(dob.t, f));
	while (dob.t[dob.i] != '.' && dob.t[dob.i])
		dob.i++;
	if (!(f.pre == 0 && !f.tag))
		dob.i++;
	condb(&f, &dob.i, &dob.t);
	conda(&f, dob.t, &dob.i, &dob.w);
	free(dob.t);
	if (dob.w > dob.i)
		return (dob.w);
	if (dob.t[0] != '-' && (f.p || f.spc))
		dob.i++;
	return (dob.i);
}
