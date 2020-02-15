/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:53:55 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

char		*plus(char *s, char c, int i)
{
	while (i < 0)
	{
		s = ft_strjoin("0", s);
		i++;
	}
	if (s[i] + c - 48 > 57)
	{
		s[i] += c - 58;
		return (plus(s, '1', i - 1));
	}
	else
		s[i] += c - 48;
	return (s);
}

char		*add(char *s, char *str)
{
	int i;

	i = ft_strlen(str);
	while (--i > -1)
	{
		if (s[i] == '2' && str[i] == '1')
			s[i] = '3';
		else if (s[i] + str[i] - '0' < 58 && str[i] > '0')
		{
			s[i] += str[i] - '0';
		}
		else if (s[i] + str[i] - '0' > '9')
			s = plus(s, str[i], i);
	}
	return (s);
}

char		*ps(char *s, char c, int i)
{
	if (s[i] == '.')
		return (ps(s, '1', i - 1));
	while (i < 0)
	{
		s = ft_strjoin("0", s);
		i++;
	}
	if (s[i] + c - 48 > 57)
	{
		s[i] += c - 58;
		return (ps(s, '1', i - 1));
	}
	else
		s[i] += c - 48;
	return (s);
}

char		*ad(char *s, char *str, int x)
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
			s = ps(s, str[i], j);
		j--;
	}
	return (s);
}
