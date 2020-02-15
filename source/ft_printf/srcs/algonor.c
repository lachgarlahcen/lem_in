/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algonor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 23:43:46 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	algonor(t_chralgo *k)
{
	if (k->b)
	{
		if (k->t[0] == '2' && k->tmp[0] == '1' && !k->t[1] && !k->tmp[1])
			k->t = "3";
		else
			k->t = ad(k->t, k->tmp, 1);
	}
	else
		k->t = k->tmp;
	free(k->tmp);
	k->tmp = ft_strjoin(k->t, ".");
	k->t = ft_strjoin(k->tmp, k->s);
	free(k->tmp);
	k->tmp = k->t;
}
