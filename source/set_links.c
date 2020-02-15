/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:42:28 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/04 18:22:12 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	link_add(t_room *room, t_room *to_add)
{
	t_link	*tmp;

	tmp = room->link;
	while (tmp->next != NULL)
	{
		if (tmp->room == to_add)
			return ;
		tmp = tmp->next;
	}
	if (tmp->room == to_add)
		return ;
	tmp->next = creat_link(to_add);
}

t_room	*find_room(char *name, t_room *room)
{
	t_room *holder;

	holder = room;
	while (holder)
	{
		if (ft_strequ(name, holder->name))
			return (holder);
		holder = holder->next;
	}
	return (NULL);
}

t_link	*creat_link(t_room *room)
{
	t_link *link;

	link = (t_link *)malloc(sizeof(t_link));
	link->room = room;
	link->flow = 1;
	link->next = NULL;
	return (link);
}

void	links_core(char *line, t_room **holder, t_room **two, t_room **room)
{
	char	**assign;

	assign = ft_strsplit(line, '-');
	*holder = find_room(assign[0], *room);
	*two = find_room(assign[1], *room);
	free_two(assign);
}

void	link_process(t_room **room, char *line)
{
	t_room	*holder;
	t_room	*two;

	while (ft_strstr(line, "-") || ft_strstr(line, "#"))
	{
		
		if (line[0] == '#')
		{
			free(line);
			line = read_line();
			continue;
		}
		links_core(line, &holder, &two, room);
		if (!holder->link)
			holder->link = creat_link(two);
		else
			link_add(holder, two);
		if (!two->link)
			two->link = creat_link(holder);
		else
			link_add(two, holder);
		free(line);
		line = read_line();
	}
}
