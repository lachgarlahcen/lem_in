/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:32:59 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/07 15:23:17 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		swap_paths(t_paths **path1, t_paths **path2)
{
	t_paths *tmp;

	tmp = *path2;
	(*path1)->next = (*path2)->next;
	tmp->next = *path1;
	*path1 = tmp;
}

t_paths		*sort_paths(t_paths *paths)
{
	int		sorted;
	t_paths	**ptr;
	t_paths	*hold;

	hold = NULL;

	sorted = 0;
	while (!sorted)
	{
		ptr = &paths;
		sorted = 1;
		while (*ptr && (*ptr)->next)
		{
			if ((*ptr)->length > (*ptr)->next->length)
			{
				sorted = 0;
				swap_paths(ptr, &(*ptr)->next);
			}
			ptr = &(*ptr)->next;
		}
	}
	return (paths);
}
