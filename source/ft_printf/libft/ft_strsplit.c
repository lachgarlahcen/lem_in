/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:10:55 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_count(const char *s, char c)
{
	int		cmp;

	cmp = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			cmp++;
		while (*s && *s != c)
			s++;
	}
	return (cmp);
}

static int		word_len(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s++)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nbr;
	int		i;

	i = 0;
	if (s)
	{
		nbr = word_count((const char *)s, c);
		if (!(t = (char **)malloc(sizeof(*t) * (nbr + 1))))
			return (NULL);
		while (nbr--)
		{
			while (*s == c && *s)
				s++;
			t[i] = ft_strsub((const char *)s, 0, word_len((const char *)s, c));
			if (t[i++] == NULL)
				return (NULL);
			s += word_len(s, c);
		}
		t[i] = NULL;
		return (t);
	}
	return (0);
}
