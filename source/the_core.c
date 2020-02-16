/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:59:45 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 14:35:35 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		test_bfs(t_graph *head)
{
	t_graph *tmp;

	tmp = head;
	return (bfs(tmp) ? 0 : 1);
}

void	the_core(t_graph *head, t_multi **multi)
{
	t_room	*tmp;
	int		a;
	int 	b;

	b = 0;
	while ((a = bfs(head)))
	{
		b++;
		reset(head->begining);
		tmp = head->end;
		while (tmp)
		{
			if (tmp != head->start)
				update_flow(tmp, tmp->previous, head);
			tmp = tmp->previous;
		}
		if (*multi == NULL)
			*multi = creat_multi(get_paths(head));
		else
			add_multi(*multi, get_paths(head));
	}
	if (!b && !a)
		exit(ft_printf("ERROR\n"));
}
