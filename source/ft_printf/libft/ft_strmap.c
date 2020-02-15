/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 22:55:57 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char *tab, char (*f)(char))
{
	size_t		i;
	char		*dest;

	if (tab)
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen(tab) + 1));
		if (dest)
		{
			i = 0;
			while (i < ft_strlen(tab))
			{
				dest[i] = f(tab[i]);
				i++;
			}
			dest[i] = '\0';
			return (dest);
		}
	}
	return (NULL);
}
