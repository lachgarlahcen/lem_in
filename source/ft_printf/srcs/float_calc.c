/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 18:59:21 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/12 05:01:35 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		negative(char **str)
{
	char *tmp;
	char *sign;

	sign = ft_strdup("-");
	tmp = *str;
	*str = ft_strjoin(sign, tmp);
	free(sign);
	free(tmp);
}

static void	more_space(t_xfloat *x)
{
	x->dump = ft_strdup("2");
	x->two = powerr(x->dump, 63);
	free(x->dump);
	x->mantissa = ft_itoa_long(x->number.row.mantissa);
	x->x = x->number.row.exponent - 16446;
	x->result = addition(x->two, x->mantissa);
	if (x->x < 0)
	{
		x->x *= -1;
		x->dump = x->two;
		x->two = ft_strdup("5");
		free(x->dump);
	}
	else
	{
		x->dump = x->two;
		x->two = ft_strdup("2");
		free(x->dump);
	}
	free(x->mantissa);
	x->mantissa = powerr(x->two, x->x);
	x->dump = x->result;
	x->result = multiplication(x->dump, x->mantissa);
}

static void	more_spc(t_xfloat *x)
{
	free(x->dump);
	free(x->mantissa);
	x->i = x->x - (int)ft_strlen(x->result) + 1;
	join_zeros(&x->result, x->i);
	if (*(x->two) != '5')
		x->x *= -1;
	free(x->two);
	x->dump = x->result;
}

static void	add_pointzero(char **str)
{
	*str = !ft_strchr(*str, '.') ? frjoin(*str, ".0") : *str;
}

char		*float_calc(long double f, t_flags *fl)
{
	t_xfloat x;

	x.number.the_float = f;
	while (special_cases(&x, fl))
	{
		if (!x.number.row.mantissa && !x.number.row.exponent)
		{
			x.result = ft_strdup("0");
			x.dump = x.result;
			x.result = add_point(x.dump, 1);
			free(x.dump);
			break ;
		}
		more_space(&x);
		more_spc(&x);
		x.result = add_point(x.dump, -x.x + (int)ft_strlen(x.result));
		free(x.dump);
		add_pointzero(&x.result);
		break ;
	}
	if (x.number.row.sign == 1 && !ft_strequ(x.result, "nan"))
		negative(&x.result);
	return (x.result);
}
