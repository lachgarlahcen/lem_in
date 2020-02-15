/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:19:57 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/12 04:57:17 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		print_lim(char *t, t_flags f)
{
	int		len;
	char	*tmp;

	if (f.p && t[0] == 'i')
		t = freejoin("+", t);
	len = ft_strlen(t);
	if (f.w > len)
	{
		tmp = ft_memset(ft_strnew(f.w - len), ' ', f.w - len);
		if (f.m)
			t = frjoin(t, tmp);
		else
			t = freejoin(tmp, t);
		free(tmp);
	}
	len = ft_strlen(t);
	write(1, t, len);
	free(t);
	return (len);
}

void	less(t_flags *f, char *t, int *i)
{
	if (t[0] != '-' && f->p)
		write(1, "+", 1);
	else if (t[0] != '-' && f->spc)
		write(1, " ", 1);
	if (f->zero && !f->m)
		while (f->w-- > *i)
			write(1, "0", 1);
	write(1, t, *i);
	if (!f->zero || f->m)
		while (f->w-- > *i)
			write(1, " ", 1);
}

int		limi(char **s, int *str)
{
	int		i;

	i = 0;
	while (i++ < 15)
	{
		if (str[i] == 0)
			return (0);
	}
	while (i++ < 78)
		if (str[i] == 1)
		{
			*s = ft_strjoin("", "nan\0");
			return (1);
		}
	if (str[0] == 0)
		*s = ft_strjoin("", "inf");
	else
		*s = ft_strjoin("", "-inf");
	return (1);
}

int		lim(char **s, int *str)
{
	int		i;

	i = 0;
	while (i++ < 10)
	{
		if (str[i] == 0)
			return (0);
	}
	while (i++ < 63)
	{
		if (str[i] == 0)
		{
			if (str[12] == 1 || str[63] == 1)
				*s = ft_strjoin("", "nan\0");
			else if (str[i] == 0 && str[0] == 0)
				*s = ft_strjoin("", "inf");
			else
				*s = ft_strjoin("", "-inf");
			return (1);
		}
	}
	return (0);
}

char	*cast(t_flags f, va_list str)
{
	char		*t;
	double		d;
	long double	dd;

	d = 0;
	dd = 0;
	if (f.ll)
	{
		dd = va_arg(str, long double);
		t = float_calc(dd, &f);
		dd ? remove_zero(&t) : 0;
		(t[0] == '.' ? join_zeros(&t, 1) : 0);
	}
	else
	{
		d = va_arg(str, double);
		t = float_calc(d, &f);
		d ? remove_zero(&t) : 0;
		(t[0] == '.' ? join_zeros(&t, 1) : 0);
	}
	return (t);
}
