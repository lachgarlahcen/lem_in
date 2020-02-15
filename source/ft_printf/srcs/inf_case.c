/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 17:26:12 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/12 04:46:41 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static char	*inf_case(t_xfloat *x, t_flags *f)
{
	char *tmp1;

	if (f->spc)
	{
		if (!f->p && !x->number.row.sign)
			tmp1 = ft_strjoin(" ", "inf");
		else if (f->m && f->p && !x->number.row.sign)
			tmp1 = ft_strdup("inf");
		else if (f->m && !f->zero)
			tmp1 = ft_strdup("inf");
		else
			tmp1 = ft_strdup("inf");
	}
	else
		tmp1 = ft_strdup("inf");
	return (tmp1);
}

int			special_cases(t_xfloat *x, t_flags *f)
{
	char	*tmp;
	char	*tmp1;

	tmp = ft_strdup("nan");
	x->result = (x->number.row.exponent == 32767 &&
			x->number.row.mantissa != 0
			? tmp : 0);
	if (x->result)
		return (0);
	tmp1 = inf_case(x, f);
	free(tmp);
	x->result = (x->number.row.exponent == 32767 &&
			x->number.row.mantissa == 0
			? frjoin(tmp1, "") : 0);
	if (x->result)
		return (0);
	free(tmp1);
	return (1);
}

int			check_round(char *num, int i)
{
	if (num[i++] != '5')
		return (0);
	while (num[i])
		if (num[i++] > '0')
			return (1);
	return (0);
}
