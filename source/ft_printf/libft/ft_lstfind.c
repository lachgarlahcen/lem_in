/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 03:19:52 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfind(t_list *lst, void *tofind)
{
	t_list	*element1;
	void	*element2;

	if (lst && tofind)
	{
		element1 = lst;
		element2 = tofind;
		while (element1 && element2)
		{
			if (!(ft_strcmp((char *)tofind, (char *)element1->content)))
				return (1);
			element1 = lst->next;
		}
	}
	return (0);
}
