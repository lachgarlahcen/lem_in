/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:45:16 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/12 04:32:09 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*pss(char *s, char c, int i, int *k)
{
	if (s[i] == '.')
		return (pss(s, '1', i - 1, k));
	while (i < 0)
	{
		s = freejoin("0", s);
		i++;
		(*k)++;
	}
	if (s[i] + c - 48 > 57)
	{
		s[i] += c - 58;
		return (pss(s, '1', i - 1, k));
	}
	else
		s[i] += c - 48;
	return (s);
}

char	*addd(char *s, char *str, int x, int *k)
{
	int i;
	int j;

	i = ft_strlen(str);
	j = ft_strlen(s) - x;
	while (--i > -1)
	{
		if (s[j] == '.')
			j--;
		if (s[j] + str[i] - '0' < 58 && str[i] > '0')
			s[j] += str[i] - '0';
		else if (s[j] + str[i] - '0' > '9')
			s = pss(s, str[i], j, k);
		j--;
	}
	return (s);
}

int		calcexxpo(int *str)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	while (++i < 16)
		if (str[16 - i] == 1)
			s += ft_atoi(power("2", i - 1));
	return (s - 16383);
}
