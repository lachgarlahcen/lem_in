/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:58:45 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		binaire(unsigned int n, int i, int *str)
{
	int x;
	int k;

	x = 1;
	if (i == 19)
		x = 12;
	else if (i == 31)
		x = 32;
	while (i >= 0)
	{
		k = n >> (i);
		if (k & 1)
			str[x] = 1;
		else
			str[x] = 0;
		x++;
		i--;
	}
	return (0);
}

int		bbinaire(unsigned int n, int i, int *str, int x)
{
	int k;

	while (i >= 0)
	{
		k = n >> (i);
		if (k & 1)
			str[x] = 1;
		else
			str[x] = 0;
		x++;
		i--;
	}
	return (0);
}
