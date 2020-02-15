/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 14:02:29 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	add_zero(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		str[0][j] = 48;
		j++;
	}
}

char	*without_point(char *str, int *point)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '.')
		i++;
	if (i != (int)ft_strlen(str))
	{
		tmp = ft_strnew(ft_strlen(str) - 1);
		*point += ft_strlen(str) - i + 1;
		j = 0;
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] != '.')
				tmp[j++] = str[i];
			i++;
		}
		tmp[i] = '\0';
		free(str);
		return (tmp);
	}
	return (str);
}

char	*add_point(char *str, int point)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strnew(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		tmp[j] = str[i];
		i++;
		j++;
		if (j == point)
		{
			tmp[j] = '.';
			j++;
		}
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*powerr(char *number, int pow)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	if (pow == 0)
		return (ft_strdup("1"));
	str = ft_strdup("1");
	while (i < pow)
	{
		tmp = str;
		str = multiplication(number, tmp);
		free(tmp);
		i++;
	}
	return (str);
}

void	join_zeros(char **str, int i)
{
	char	*tmp;
	char	*zero;

	zero = ft_strdup("0");
	while (i > 0)
	{
		tmp = *str;
		str[0] = ft_strjoin(zero, tmp);
		free(tmp);
		i--;
	}
	free(zero);
}
