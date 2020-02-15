/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:15:16 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/09 04:45:07 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*creat_path(t_room *room)
{
	t_path	*path;

	path = (t_path *)malloc(sizeof(t_path));
	path->room = room;
	path->ant = 0;
	path->next = NULL;
	return (path);
}

t_paths	*creat_paths(t_path *path)
{
	t_paths	*paths;

	paths = (t_paths *)malloc(sizeof(t_paths));
	paths->ants = 0;
	paths->length = path_length(path);
	paths->path = path;
	paths->next = NULL;
	return (paths);
}

void	add_path(t_path *path, t_room *room)
{
	t_path	*tmp;

	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = creat_path(room);
}

void	add_paths(t_paths *paths, t_path *path)
{
	t_paths	*tmp;

	tmp = paths;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = creat_paths(path);
}

void	creating_path(t_link **tmp, t_path **path)
{
	while ((*tmp)->flow == 2)
	{
		if (*path == NULL)
			*path = creat_path((*tmp)->room);
		else
			add_path(*path, (*tmp)->room);
		(*tmp) = (*tmp)->room->link;
		while ((*tmp)->flow != 2 && (*tmp)->next)
			(*tmp) = (*tmp)->next;
	}
}
