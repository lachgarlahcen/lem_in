/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 03:57:18 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstlen(t_list *lst)
{
	t_list	*element;
	int		c;

	c = 0;
	if (lst)
	{
		element = lst;
		while (element)
		{
			element = lst->next;
			c++;
		}
		return (c);
	}
	return (0);
}
