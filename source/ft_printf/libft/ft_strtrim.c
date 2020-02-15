/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 00:08:44 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		check(char const *s, char *str)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i != (int)ft_strlen((char *)s))
		return (0);
	str[0] = '\0';
	return (1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		cmp;

	i = 0;
	cmp = 0;
	if (!s)
		return (NULL);
	if (!(check(s, str = (char *)malloc(sizeof(char)))))
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		j = ft_strlen((char *)s) - 1;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		if (!(str = malloc(j - i + 2)))
			return (NULL);
		while (i <= j)
			str[cmp++] = s[i++];
		str[cmp] = '\0';
	}
	return (str);
}
