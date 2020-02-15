/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:11:32 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/14 21:10:12 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	push_start(t_paths *paths, t_info *info, int *i)
{
	t_paths	*tmp;

	tmp = paths;
	(void) info;
	while (tmp)
	{
		if (!(tmp->path->ant) && tmp->ants)
		{
			tmp->path->ant = *i;
			tmp->ants -= 1;
			ft_printf("L%d-%s ", *i, tmp->path->room->name);
			*i += 1;
		}
		tmp = tmp->next;
	}
}

void	ft_push_room(t_path *path, t_graph *graph, t_info *info)
{
	t_path	*temp;

	temp = path;
	if (temp->next)
		ft_push_room(temp->next, graph, info);
	if (temp->next && temp->ant && !(temp->next->ant))
	{
		if (temp->next->room != graph->end)
			temp->next->ant = temp->ant;
		ft_printf("L%d-%s ", temp->ant, temp->next->room->name);
		temp->ant = 0;
		if (temp->room == graph->end)
			info->ants -= 1;
	}
}

void	push(t_paths *paths, t_graph *graph, t_info *info)
{
	t_paths	*tmp;
	t_path	*temp;

	tmp = paths;
	while (tmp)
	{
		temp = tmp->path;
		ft_push_room(temp, graph, info);
		tmp = tmp->next;
	}
}

void	loop_path(t_paths *paths, t_info *info, t_graph *graph)
{
	int		i;
	t_paths	*tmp;

	i = 1;
	while ((info->instructions)--)
	{
		tmp = paths;
		push(paths, graph, info);
		push_start(paths, info, &i);
		ft_printf("\n");
	}
}
