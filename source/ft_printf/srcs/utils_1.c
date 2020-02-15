/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:55:03 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	swap_str(char **str1, char **str2)
{
	char	*tmp;

	if (ft_strlen(*str1) < ft_strlen(*str2))
	{
		tmp = *str1;
		*str1 = *str2;
		*str2 = tmp;
	}
}

void	reverse_str(char **str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str[0]) - 1;
	while (i <= j)
	{
		tmp = str[0][i];
		str[0][i] = str[0][j];
		str[0][j] = tmp;
		i++;
		j--;
	}
}

void	remove_zero(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = *str;
	if (ft_strlen(tmp) > 1)
		while (tmp[i] == '0' && tmp[i] != '\0')
		{
			i++;
			if (tmp[i] != '0' && tmp[i] != '\0')
			{
				*str = ft_strsub(tmp, i, ft_strlen(*str) - i);
				free(tmp);
				return ;
			}
		}
}

void	free_addition(t_addition *args)
{
	free(args->str1_1);
	free(args->part1);
	free(args->part2);
	free(args->str1_2);
	free(args->str2_1);
	free(args->str2_2);
}

void	lesss(int *rest, char **tmp, char **str1, int *i)
{
	while (*rest == 1)
	{
		tmp[0][*i] = str1[0][*i] + *rest;
		*rest = 0;
		if (tmp[0][*i] > 57)
		{
			tmp[0][*i] -= 10;
			*rest = 1;
		}
		if (*i >= (int)ft_strlen(str1[0]))
			tmp[0][*i] = '1';
		i[0]++;
	}
	while (*i < (int)ft_strlen(str1[0]))
	{
		tmp[0][*i] = str1[0][*i];
		i[0]++;
	}
}
