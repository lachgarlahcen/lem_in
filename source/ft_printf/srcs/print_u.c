/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:49:36 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	condflh(t_flags f, char **c, unsigned long long int i, int *len)
{
	if (f.l == 1)
		*c = ft_itoa_uns((unsigned long int)i);
	else if (f.l == 2 || f.z || f.j)
		*c = ft_itoa_uns((unsigned long long int)i);
	else if (f.h == 1)
		*c = ft_itoa_uns((unsigned short int)i);
	else if (f.h == 2)
		*c = ft_itoa_uns((unsigned char)i);
	else
		*c = ft_itoa_uns((unsigned int)i);
	*len = ft_strlen(*c);
	if (c[0][0] == '0' && f.pre == 0)
		c[0][0] = '\0';
}

int			print_u(va_list str, t_flags f)
{
	unsigned long long int	i;
	char					*c;
	int						len;

	i = va_arg(str, unsigned long long int);
	condflh(f, &c, i, &len);
	if (f.pre - len >= 0)
		c = freesetjoin('0', f.pre - len, c);
	if (f.w > (int)ft_strlen(c))
	{
		if (f.zero && f.pre == -1 && f.m == 0)
			c = freesetjoin('0', f.w - ft_strlen(c), c);
		if (!(f.zero && f.pre == -1) && f.m == 0)
			c = freesetjoin(' ', f.w - ft_strlen(c), c);
		else if (f.m == 1)
			c = frsetjoin(c, f.w - ft_strlen(c), ' ');
	}
	write(1, c, ft_strlen(c));
	len = ft_strlen(c);
	free(c);
	return (len);
}
