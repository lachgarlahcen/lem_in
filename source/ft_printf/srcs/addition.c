/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 12:58:06 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 21:39:10 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*part_one(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	tmp = ft_strsub(str, 0, i);
	return (tmp);
}

char		*part_two(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		j = i;
		i = ft_strlen(str);
		tmp = ft_strsub(str, j, i - j);
		return (tmp);
	}
	else
		tmp = ft_strdup("0");
	return (tmp);
}

char		*add_part_one(char *str1, char *str2, int *rest)
{
	int		i;
	char	*tmp;

	swap_str(&str1, &str2);
	reverse_str(&str1);
	reverse_str(&str2);
	tmp = ft_strnew((int)ft_strlen(str1) + 1);
	i = -1;
	while (++i < (int)ft_strlen(str2))
	{
		tmp[i] = str1[i] + str2[i] + *rest - 48;
		*rest = 0;
		if (tmp[i] > 57)
		{
			tmp[i] -= 10;
			*rest = 1;
		}
	}
	tmp[i] = '\0';
	lesss(rest, &tmp, &str1, &i);
	reverse_str(&tmp);
	return (tmp);
}

char		*add_part_two(char *str1, char *str2, int *rest)
{
	int		i;
	char	*tmp;

	swap_str(&str1, &str2);
	tmp = ft_strnew((int)ft_strlen(str1));
	i = ft_strlen(str2);
	*rest = 0;
	while (--i > 0)
	{
		tmp[i - 1] = str1[i] + str2[i] + *rest - 48;
		*rest = 0;
		if (tmp[i - 1] > 57)
		{
			tmp[i - 1] -= 10;
			*rest = 1;
		}
	}
	i = ft_strlen(str2);
	while (i < (int)ft_strlen(str1))
	{
		tmp[i - 1] = str1[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char		*addition(char *str1, char *str2)
{
	int			rest;
	char		*result;
	t_addition	args;

	rest = 0;
	args.str1_1 = part_two(str1);
	args.str2_1 = part_two(str2);
	args.part1 = add_part_two(args.str1_1, args.str2_1, &rest);
	args.str1_2 = part_one(str1);
	args.str2_2 = part_one(str2);
	args.part2 = add_part_one(args.str1_2, args.str2_2, &rest);
	result = ft_strjoin(args.part2, args.part1);
	free_addition(&args);
	return (result);
}
