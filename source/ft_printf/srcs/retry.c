/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:58:04 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		init_f(t_flags *f)
{
	f->p = 0;
	f->m = 0;
	f->tag = 0;
	f->pre = -1;
	f->spc = 0;
	f->z = 0;
	f->j = 0;
	f->w = 0;
	f->h = 0;
	f->l = 0;
	f->ll = 0;
	f->zero = 0;
}

static void	bcw(t_flags f, const char **fmt, int *count, va_list args)
{
	(*fmt)++;
	*fmt += check(*fmt, &f);
	if (**fmt == 'd' || **fmt == 'i')
		*count += print_d(args, f);
	else if (**fmt == 'c')
		*count += print_c(args, f);
	else if (**fmt == 's')
		*count += print_s(args, f);
	else if (**fmt == 'p')
		*count += print_p(args, f);
	else if (**fmt == 'u')
		*count += print_u(args, f);
	else if (**fmt == 'o')
		*count += print_o(args, f);
	else if (**fmt == 'f')
		*count += print_f(args, f);
	else if (**fmt == 'x' || **fmt == 'X')
		*count += print_x(args, f, (**fmt) - 33);
	else if (**fmt == 'b')
		*count += print_b(args, f);
	else if (**fmt == 'e')
		*count += print_e(args, f);
	else
		*count += print_a(*fmt, f);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_flags	f;
	int		count;

	init_f(&f);
	va_start(args, fmt);
	count = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
			bcw(f, &fmt, &count, args);
		else if (*fmt)
		{
			count++;
			write(1, fmt, 1);
		}
		fmt++;
	}
	va_end(args);
	return (count);
}
