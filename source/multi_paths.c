/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:18:09 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/09 21:25:02 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths	*get_paths(t_graph *graph)
{
	t_link	*tmp;
	t_link	*temp;
	t_path	*path;
	t_paths	*paths;

	paths = NULL;
	temp = graph->end->link;
	while (temp)
	{
		path = NULL;
		tmp = temp;
		creating_path(&tmp, &path);
		if (temp->flow == 2)
		{
			if (paths == NULL)
				paths = creat_paths(path);
			else
				add_paths(paths, path);
		}
		temp = temp->next;
	}
	return (paths);
}

t_multi	*creat_multi(t_paths *paths)
{
	t_multi	*multi;

	multi = malloc(sizeof(t_multi));
	multi->paths = paths;
	multi->next = NULL;
	return (multi);
}

void	add_multi(t_multi *multi, t_paths *paths)
{
	t_multi	*tmp;

	tmp = multi;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = creat_multi(paths);
}
