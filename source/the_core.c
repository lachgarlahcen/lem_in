/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:59:45 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/04 18:40:12 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	the_core(t_graph *head, t_multi **multi)
{
	t_room	*tmp;

	while ((bfs(head)))
	{
		reset(head->begining);
		tmp = head->end;
		while (tmp)
		{
			if (tmp != head->start)
				update_flow(tmp, tmp->previous, head);
			tmp = tmp->previous;
		}
		if (*multi == NULL)
		{
			*multi = creat_multi(get_paths(head));
		}
		else
			add_multi(*multi, get_paths(head));
	}
}
