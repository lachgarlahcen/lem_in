/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 03:38:55 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*to_hexa(long int n, int k, t_flags f)
{
	char		*hexa;
	long int	i;
	long int	temp;

	hexa = ft_memset(ft_strnew(13), '0', 13);
	i = 11;
	if (n == 0 && f.pre != 0)
		return (ft_memset(ft_strnew(1), '0', 1));
	else if (n == 0 && f.pre == 0)
		return (ft_memset(ft_strnew(1), '\0', 1));
	while (n != 0)
	{
		if ((temp = n % 16) < 10)
			hexa[i--] = temp + 48;
		else
			hexa[i--] = temp + k;
		n = n / 16;
	}
	hexa[12] = '\0';
	if (i > 0)
		return (ft_strsub(hexa, i + 1, ft_strlen(hexa) - i));
	return (hexa);
}
