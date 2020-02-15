/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 22:59:24 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int			num(long long int n)
{
	if (n < 0)
		n *= -1;
	if (n < 10)
		return (1);
	return (1 + num(n / 10));
}

static int	num_uns(unsigned long long int n)
{
	if (n < 10)
		return (1);
	return (1 + num(n / 10));
}

static void	ft_nit_variables(int *c, long long int *nbim, long long int n)
{
	*nbim = n;
	*c = num(n);
}

char		*ft_iitoa(long long int n)
{
	char			*arr;
	int				c;
	long long int	nbim;

	ft_nit_variables(&c, &nbim, n);
	if (n < 0)
	{
		if (!(arr = (char *)malloc(c + 2)))
			return (NULL);
		nbim *= -1;
	}
	else
		arr = (char *)malloc(c + 1);
	arr[c--] = '\0';
	arr[0] = (nbim == 0) ? '0' : arr[0];
	while (nbim != 0)
	{
		arr[c--] = ((nbim % 10) + '0');
		nbim /= 10;
	}
	return (n == (-9223372036854775807 - 1) ?
			ft_strdup("-9223372036854775808") : arr);
}

char		*ft_itoa_uns(unsigned long long int n)
{
	char					*arr;
	int						c;
	unsigned long long int	nbim;

	nbim = n;
	c = num_uns(n);
	arr = (char *)malloc(c + 1);
	arr[c--] = '\0';
	arr[0] = (nbim == 0) ? '0' : arr[0];
	while (nbim != 0)
	{
		arr[c--] = ((nbim % 10) + '0');
		nbim /= 10;
	}
	return (arr);
}
