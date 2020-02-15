/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:36:38 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assign(char *tab, int nbr, int size, int sign)
{
	if (!(tab = (char *)malloc(sizeof(char) * nbr == 0 ? 2 : (size + 1))))
		return (NULL);
	tab[size--] = '\0';
	if (nbr == 0)
	{
		tab[0] = '0';
		tab[1] = '\0';
	}
	while (nbr != 0)
	{
		if (size == 1 && sign == -1)
		{
			tab[0] = '-';
		}
		tab[size--] = (nbr % 10) + 48;
		nbr = (nbr - (nbr % 10)) / 10;
	}
	return (tab);
}

char		*ft_itoa(int nbr)
{
	char	*tab;
	int		size;
	int		temp;
	int		sign;

	size = 0;
	sign = 1;
	tab = NULL;
	if (nbr < 0)
	{
		if (nbr == -2147483648)
			return (ft_strdup("-2147483648"));
		size++;
		sign = -1;
		nbr *= sign;
	}
	temp = nbr;
	while (temp != 0)
	{
		size++;
		temp = (temp - (temp % 10)) / 10;
	}
	tab = assign(tab, nbr, size, sign);
	return (tab);
}
