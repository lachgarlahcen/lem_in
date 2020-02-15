/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:12:46 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char *tab, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (tab)
	{
		dest = (char *)malloc(sizeof(char) * (ft_strlen(tab) + 1));
		if (dest)
		{
			i = 0;
			while ((int)i < (int)ft_strlen(tab))
			{
				dest[i] = f(i, tab[i]);
				i++;
			}
			dest[i] = '\0';
			return (dest);
		}
	}
	return (NULL);
}
