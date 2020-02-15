/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:45:28 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		l;

	if (s1)
	{
		l = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
		s3 = (char *)malloc(sizeof(char const) * l);
		if (s3)
		{
			ft_strcpy(s3, s1);
			ft_strcat(s3, s2);
			return (s3);
		}
	}
	return (NULL);
}
