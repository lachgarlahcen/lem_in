/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 23:04:21 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*strk;

	strk = (char *)str;
	i = 0;
	while (i < n)
	{
		strk[i] = 0;
		i++;
	}
	str = (void *)strk;
	return (str);
}
