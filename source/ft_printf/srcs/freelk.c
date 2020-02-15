/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freelk.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 01:17:49 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

char	*freejoin(char *c, char *s)
{
	char	*tmp;

	tmp = ft_strjoin(c, s);
	free(s);
	return (tmp);
}

char	*frjoin(char *c, char *s)
{
	char	*tmp;

	tmp = ft_strjoin(c, s);
	free(c);
	return (tmp);
}

char	*frsetjoin(char *s, int l, char c)
{
	char	*tmp;
	char	*t;

	t = ft_memset(ft_strnew(l), c, l);
	tmp = ft_strjoin(s, t);
	free(t);
	free(s);
	return (tmp);
}

char	*freesetjoin(char c, int l, char *s)
{
	char	*tmp;
	char	*t;

	t = ft_memset(ft_strnew(l), c, l);
	tmp = ft_strjoin(t, s);
	free(t);
	free(s);
	return (tmp);
}

char	*fresetjoin(char c, int l, char *s)
{
	char	*tmp;
	char	*t;

	t = ft_memset(ft_strnew(l), c, l);
	tmp = ft_strjoin(t, s);
	free(t);
	return (tmp);
}
