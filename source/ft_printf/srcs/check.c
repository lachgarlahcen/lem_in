/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 11:06:54 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

int			get_w(const char *str, t_flags *f, int i)
{
	if (str[i] == '0')
	{
		f->zero = 1;
		i++;
	}
	while (str[i] < 58 && str[i] > 47)
	{
		f->w *= 10;
		f->w += str[i] - 48;
		i++;
	}
	return (i);
}

int			get_pre(const char *str, t_flags *f, int i)
{
	f->pre = 0;
	while (str[i] < 58 && str[i] > 47)
	{
		f->pre *= 10;
		f->pre += str[i] - 48;
		i++;
	}
	return (i);
}

static int	cond(const char *str, int *i, t_flags *f)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		(*i)++;
		if (f->h == 0)
			f->h = 2;
	}
	else if (str[*i] == 'h' && str[*i + 1] != 'h')
		f->h = 1;
	else if (str[*i] == 'l' && f->l == 0)
		f->l = 1;
	else if (str[*i] == 'l' && str[*i - 1] == 'l')
		f->l = 2;
	else if (str[*i] == 'z')
		f->z = 1;
	else if (str[*i] == 'j')
		f->j = 1;
	else if (str[*i] == 'L')
		f->ll = 1;
	else
		return (1);
	return (0);
}

int			check(const char *str, t_flags *f)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			f->m = 1;
		else if (str[i] == '+')
			f->p = 1;
		else if (str[i] == '#')
			f->tag = 1;
		else if (str[i] == ' ')
			f->spc = 1;
		else if (str[i] > 47 && str[i] < 58)
			i = get_w(str, f, i) - 1;
		else if (str[i] == '.')
			i = get_pre(str, f, i + 1) - 1;
		else if (cond(str, &i, f))
			break ;
		i++;
	}
	return (i);
}
