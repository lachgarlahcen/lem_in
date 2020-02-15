/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 22:55:18 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	i = -1;
	d = dest;
	s = (char *)src;
	while (++i < n)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
			return (d + i + 1);
	}
	return (NULL);
}
