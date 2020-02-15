/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 09:44:45 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		fill(char *x, char **s, int *t, int *y)
{
	s[*t - 1] = ft_strjoin("", x);
	(*t)++;
	(*y)--;
}

void		cnt(char **x, char **s, int i)
{
	int j;

	j = 0;
	while (j < i)
	{
		*x = multp(*x, s[j]);
		j++;
	}
}

int			stk(int y)
{
	int i;

	i = 0;
	while (y > 1)
	{
		if (y % 2 == 1)
		{
			i++;
			y--;
		}
		y /= 2;
	}
	return (i);
}

char		*power(char *x, int y)
{
	int		i;
	int		t;
	char	**stack;

	if (y == 0)
		return ("1");
	i = stk(y);
	t = 1;
	stack = (char **)malloc(i * sizeof(char *));
	while (y > 1)
	{
		if (y % 2 == 1)
			fill(x, stack, &t, &y);
		x = multp(x, x);
		y /= 2;
	}
	cnt(&x, stack, i);
	return (x + clean(x));
}
