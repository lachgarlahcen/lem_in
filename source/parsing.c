/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:26:08 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 23:24:08 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	*read_line(void)
{
	char *line;
	char *tmp_str;
	char tmp[2];

	line = ft_strdup("");
	while (read(0, tmp, 1) == 1 && tmp[0] != '\n')
	{
		tmp[1] = 0;
		tmp_str = ft_strjoin(line, tmp);
		if (*line)
			ft_strdel(&line);
		line = ft_strdup(tmp_str);
		ft_strdel(&tmp_str);
	}
	return (line);
}

void	add_end(t_paths **paths, t_room *end)
{
	t_paths *tmp;

	tmp = *paths;
	while (*paths)
	{
		add_path((*paths)->path, end);
		(*paths) = (*paths)->next;
	}
	*paths = tmp;
}


void	get_info(void)
{
	t_info	info;
	t_graph	head;
	t_multi	*multi;
	int		rest;
	t_lemin l;

	multi = NULL;
	init(&info, &head, &l);
	check_validation(&l, &head, &info);
	the_core(&head, &multi);
	multi = optimal_path(multi, &info);
	multi->paths = sort_paths(multi->paths);
	add_end(&multi->paths, head.end);
	rest = ants_path(multi, &info);
	add_rest(multi->paths, rest, &info);
	loop_path(multi->paths, &info, &head);
	free_paths(multi->paths);
	free_multi(multi, &l);
	free_room((&head)->begining);

}

int		main()
{
	get_info();
	return (0);
}
