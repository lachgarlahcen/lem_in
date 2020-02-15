/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 23:55:30 by wbensaid          #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static int		neg(char *t, int i, int j, int k)
{
	while (t[j] == '0')
		j++;
	i = j;
	if (t[j + 7] > '4')
		t = addd(t, "1", ft_strlen(t) - j - 6, &i);
	if (k)
		ft_putchar('-');
	if (t[j - 1] == '1' || (t[j - 1] == '.' && t[j - 2] == '1'))
		write(1, "1", 1 + (i--) * 0);
	else
		ft_putchar(t[j++]);
	ft_putchar('.');
	while (j < i + 7)
		ft_putchar(t[j++]);
	t = ft_itoa(i - 1 - k);
	if (t[0] == '0')
		write(1, "e+", 2);
	else
		write(1, "e-", 2);
	if (i - 1 - k < 10)
		t = ft_strjoin("0", t);
	write(1, t, ft_strlen(t));
	return (10 + ft_strlen(t) + k);
}

static int		pos(char *t, int i, int k)
{
	int j;

	j = 1;
	ft_putchar(t[0]);
	if (k)
		ft_putchar(t[1]);
	ft_putchar('.');
	while (j < 7)
	{
		if (t[j + k] != '.')
			ft_putchar(t[j + k]);
		j++;
	}
	if (i < 7 + k)
		ft_putchar(t[7 + k]);
	write(1, "e+", 2);
	t = ft_itoa(i - 1 - k);
	if (i - 1 - k < 10)
		t = ft_strjoin("0", t);
	write(1, t, ft_strlen(t));
	return (10 + ft_strlen(t) + k);
}

int				print_e(va_list str, t_flags f)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	j = 0;
	t = cast(f, str);
	if (t[1] >= 'a' && t[1] < 'z')
		return (print_lim(t, f));
	if (t[0] == '-')
		j++;
	while (t[i] != '.')
		i++;
	if (i + j > 7 + j && t[7 + j] > '4' && t[0 + j] != '0')
		t = addd(t, "1", ft_strlen(t) - 7 - j + 1, &i);
	if (i + j < 7 + j && t[8 + j] > '4' && t[0 + j] != '0')
		t = addd(t, "1", ft_strlen(t) - 8 - j + 1, &i);
	if (i + j == 7 + j && t[8 + j] > '4' && t[0 + j] != '0')
		t = addd(t, "1", ft_strlen(t) - 8 - j + 1, &i);
	if (t[0 + j] == '0')
		i = neg(t, i, 2 + j, j);
	else
		i = pos(t, i, j);
	return (i);
}
