/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mltp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:54:26 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

int			clean(char *s)
{
	int i;

	i = 0;
	while (s[i] == 48)
		i++;
	if (i == (int)ft_strlen(s))
		return (i - 1);
	return (i);
}

void		mltp(char *s, char c, char *ans, int x)
{
	while (x < 0)
	{
		ans = ft_strjoin("0", ans);
		x++;
	}
	if (c > 10)
	{
		ans[x--] = c % 10 + 48;
		return (mltp(s, (c - (c % 10)) / 10, ans, x));
	}
	else
		ans[x--] = c + 48;
}

char		*multip(char *s, char c)
{
	char	*ans;
	char	*tmp;
	int		j;
	int		len;

	len = ft_strlen(s) - 1;
	tmp = ft_memset(ft_strnew(len + 2), '0', len + 2);
	j = len;
	while (j > -1)
	{
		ans = ft_memset(ft_strnew(1), '0', 1);
		if ((s[j] - 48) * c < 10)
			ans[0] = (c * (s[j] - 48)) + 48;
		else
		{
			ans = ft_memset(ft_strnew(2), '0', 2);
			mltp(s, (c * (s[j] - 48)), ans, 1);
		}
		j--;
		tmp = ad(tmp, ans, len - j);
	}
	return (tmp);
}

char		*multp(char *s, char *str)
{
	char	**tmp;
	char	*ans;
	int		i;
	int		len1;
	int		len2;

	i = -1;
	len1 = ft_strlen(s) - 1;
	len2 = ft_strlen(str);
	tmp = (char **)malloc(10 * sizeof(char *));
	while (++i < 10)
		tmp[i] = NULL;
	tmp[1] = ft_strjoin("", s);
	ans = ft_memset(ft_strnew(len1 + len2 + 1), '0', len1 + len2 + 1);
	i = len2;
	while (--i > -1)
	{
		if (str[i] != '0')
		{
			if (tmp[str[i] - 48] == NULL)
				tmp[str[i] - 48] = multip(s, str[i] - 48);
			ans = ad(ans, tmp[str[i] - 48], len2 - i);
		}
	}
	return (ans);
}
