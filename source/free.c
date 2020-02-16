/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:22:51 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 06:30:37 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_rooms(t_room *room)
{
	while (room->next)
	{
		free(room->name);
		while (room->link)
		{
			free(room->link);
			room->link = room->link->next;
		}
		free(room);
		room = room->next;
	}
}

void	free_path(t_path *path)
{
	while (path->next)
	{
		free(path);
		path = path->next;
	}
}

void	free_paths(t_paths *paths)
{
	while (paths->next)
	{
		free_path(paths->path);
		free(paths);
		paths = paths->next;
	}
}

void	free_multi(t_multi *multi)
{
	while (multi->next)
	{
		free_paths(multi->paths);
		free(multi);
		multi = multi->next;
	}
}
