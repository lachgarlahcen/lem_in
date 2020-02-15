/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 21:47:14 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

static	void	swap(int i, int j, char **hexa)
{
	char tmp;

	while (--i > ++j)
	{
		tmp = hexa[0][j];
		hexa[0][j] = hexa[0][i];
		hexa[0][i] = tmp;
	}
}

char			*to_hex(unsigned long long int n, int k, t_flags f)
{
	char					*hexa;
	int						j;
	int						i;
	unsigned long long int	temp;

	hexa = (char *)malloc(sizeof(char *) * 20);
	i = 0;
	j = -1;
	if (n == 0 && f.pre != 0)
	{
		hexa[0] = '0';
		hexa[1] = '\0';
		return (hexa);
	}
	while (n != 0)
	{
		if ((temp = n % 16) < 10)
			hexa[i++] = temp + 48;
		else
			hexa[i++] = temp + k;
		n = n / 16;
	}
	hexa[i] = '\0';
	swap(i, j, &hexa);
	return (hexa);
}

static void		kkll(t_flags *f, char **c, int j)
{
	if (f->tag && j)
		f->w -= 2;
	if (f->zero && f->pre == -1 && f->m == 0 && f->w > (int)ft_strlen(*c))
		*c = freesetjoin('0', f->w - ft_strlen(*c), *c);
	if (f->tag && j)
	{
		*c = freejoin("0x", *c);
		f->w += 2;
	}
	if (!(f->zero && f->pre == -1) && f->m == 0 && f->w > (int)ft_strlen(*c))
		*c = freesetjoin(' ', f->w - ft_strlen(*c), *c);
	else if (f->m && f->w > (int)ft_strlen(*c))
		*c = frsetjoin(*c, f->w - ft_strlen(*c), ' ');
}

static void		cnt(char **c, int j, int k, t_flags *f)
{
	int len;

	len = ft_strlen(*c);
	if (f->pre - len >= 0)
		*c = freesetjoin('0', f->pre - len, *c);
	if (f->w > (int)len)
		kkll(f, c, j);
	else if (f->tag && j)
		*c = freejoin("0x", *c);
	if (f->tag && j && k < 80)
		c[0][1] -= 32;
}

int				print_x(va_list str, t_flags f, int k)
{
	unsigned long long int	i;
	char					*c;
	int						len;
	int						j;

	i = va_arg(str, unsigned long long int);
	j = 0;
	if (i > 0)
		j = 1;
	if (f.l == 1)
		c = to_hex((unsigned long int)i, k, f);
	else if (f.l == 2 || f.j || f.z)
		c = to_hex((unsigned long long int)i, k, f);
	else if (f.h == 1)
		c = to_hex((unsigned short int)i, k, f);
	else if (f.h == 2)
		c = to_hex((unsigned char)i, k, f);
	else
		c = to_hex((unsigned int)i, k, f);
	cnt(&c, j, k, &f);
	write(1, c, ft_strlen(c));
	len = ft_strlen(c);
	free(c);
	return (len);
}
