/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:36:59 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static void	check_c(char **c, t_flags f, int *len)
{
	char *tmp;

	*len = f.w - ft_strlen(*c);
	if (f.pre < (int)ft_strlen(*c) && f.pre > -1)
		*len = f.w - f.pre;
	if (f.pre >= 0)
		*c = ft_strsub(*c, 0, f.pre);
	if (*len > 0)
	{
		tmp = ft_strnew(*len);
		if (f.zero && !f.m)
			tmp = ft_memset(tmp, '0', *len);
		else
			tmp = ft_memset(tmp, ' ', *len);
		if (f.m && f.pre >= 0)
			*c = frjoin(*c, tmp);
		else if (!f.m && f.pre >= 0)
			*c = freejoin(tmp, *c);
		else if (f.m && f.pre == -1)
			*c = ft_strjoin(*c, tmp);
		else if (!f.m && f.pre == -1)
			*c = ft_strjoin(tmp, *c);
		free(tmp);
	}
}

int			print_s(va_list str, t_flags f)
{
	char	*c;
	int		len;
	int		len2;

	c = va_arg(str, char *);
	if (!c)
	{
		c = ft_strnew(6);
		c = "(null)";
	}
	check_c(&c, f, &len);
	len2 = ft_strlen(c);
	write(1, c, len2);
	if (len > 0)
		free(c);
	return (len2);
}
