/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:37:12 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dl;
	size_t	i;
	size_t	sl;
	size_t	s;

	s = size;
	i = 0;
	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	while ((i < (size - dl - 1)) && i < sl && (size > dl))
	{
		dest[i + dl] = src[i];
		i++;
	}
	if (size - dl - 1 > 0)
		dest[i + dl] = '\0';
	if (s < dl)
		return (s + sl);
	else
		return (dl + sl);
}
