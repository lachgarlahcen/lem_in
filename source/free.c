/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:22:51 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/18 05:48:06 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_room(t_room *room)
{
	t_room *tmp;
	t_link *temp;

	while (room)
	{
		tmp = room;
		while (room->link)
		{
			temp = room->link;
			room->link = room->link->next;
			free(temp);
		}
		room = room->next;
		free(tmp->name);
		free(tmp);
	}
}

void	free_path(t_path *path)
{
	t_path	*tmp;

	while (path)
	{
		tmp = path;
		path = path->next;
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

	if (l)
		free_lemin(l);
	while (multi)
	{
		tmp = multi;
		multi = multi->next;
		free_paths(tmp->paths);
		free(tmp);
	}
}
