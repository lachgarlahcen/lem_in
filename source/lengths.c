/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 12:10:12 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 06:37:14 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		path_length(t_path *path)
{
	t_path	*tmp;
	int		result;

	result = 0;
	tmp = path;
	while (tmp)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

int		paths_length(t_paths *path)
{
	t_paths	*tmp;
	int		result;

	result = 0;
	tmp = path;
	while (tmp)
	{
		result++;
		tmp = tmp->next;
	}
	return (result);
}

int		depth(t_multi *multi)
{
	t_paths *paths;
	int		depth;

	paths = multi->paths;
	depth = 0;
	while (paths)
	{
		depth += path_length(paths->path);
		paths = paths->next;
	}
	return (depth);
}

t_multi	*optimal_path(t_multi *tmp, t_info *info)
{
	t_multi		*multi;
	t_multi		*result;
	float		min;

	multi = tmp;
	min = ((info->ants + depth(multi)) / paths_length(multi->paths));
	while (multi)
	{
		if (((info->ants + depth(multi)) / paths_length(multi->paths)) <= min)
		{
			result = multi;
			min = ((info->ants + depth(multi)) / paths_length(multi->paths));
		}
		multi = multi->next;
	}
	result = creat_multi(result->paths);
	free_multi(tmp);
	info->instructions = (min > (int)min ? (int)(min + 1) : (int)min);
	return (result);
}

int		ants_path(t_multi *multi, t_info *info)
{
	t_paths *paths;
	int		pivot;
	t_paths *tmp;
	t_paths *hold;
	int		rest;

	paths = multi->paths;
	hold = paths;
	rest = 0;
	while (paths)
	{
		pivot = 0;
		tmp = hold;
		while (tmp != paths)
		{
			pivot += paths->length - tmp->length;
			tmp = tmp->next;
		}
		tmp = tmp->next;
		while (tmp)
		{
			pivot -= tmp->length - paths->length;
			tmp = tmp->next;
		}
		paths->ants = ((info->ants - pivot) / paths_length(hold));
		rest += paths->ants;
		paths = paths->next;
	}
	return (rest);
}

void	add_rest(t_paths *paths, int rest, t_info *info)
{
	t_paths	*tmp;

	tmp = paths;
	rest = info->ants - rest;
	while (rest)
	{
		tmp->ants += 1;
		tmp = tmp->next;
		rest -= 1;
	}
}
