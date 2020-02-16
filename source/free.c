/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:22:51 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 15:16:10 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_rooms(t_room *room)
{
	t_room *tmp;

	while (room)
	{
		tmp = room;
		room = room->next;
		free(tmp->name);
		free(tmp);
		/*while (room->link)
		{
			free(room->link);
			room->link = room->link->next;
		}*/
	}
}

void	free_path(t_path *path)
{
	t_path * tmp;
	
	while (path)
	{
		tmp = path;
		path = path->next;
		//free_rooms(tmp->room);
		free(tmp);
	}
}

void	free_paths(t_paths *paths)
{
	t_paths *tmp;

	while (paths)
	{
		tmp = paths;
		paths = paths->next;
		free_path(tmp->path);
		free(tmp);
	}
}

void	free_multi(t_multi *multi, t_lemin *l)
{
	t_multi *tmp;

	free_lemin(l);
	while (multi)
	{
		tmp = multi;
		multi = multi->next;
		free_paths(tmp->paths);
		free(tmp);
	}
}
