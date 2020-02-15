/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:42:30 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_itoa_long(unsigned long long n)
{
	unsigned long long		i;
	unsigned long long		nb;
	char					*str;

	nb = 0;
	i = n;
	while (n /= 10)
		nb++;
	nb += 1;
	if (!(str = ft_strnew(nb)))
		return (NULL);
	str[--nb] = (i % 10) + '0';
	while (i /= 10)
		str[--nb] = i % 10 + '0';
	return (str);
}
