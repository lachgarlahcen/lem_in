/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rooms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 10:15:26 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/03 10:59:33 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*create_room(char *name, int x, int y)
{
	t_room *room;

	if (!(room = malloc(sizeof(t_room))))
		exit(1);
	room->name = ft_strdup(name);
	room->cord[0] = x;
	room->cord[1] = y;
	room->visited = 0;
	room->capacity = 0;
	room->link = NULL;
	room->previous = NULL;
	room->next = NULL;
	return (room);
}

t_room	*add_room(t_room **room, char *name, int x, int y)
{
	t_room	*tmp;
	if (!(*room))
	{
		*room = create_room(name, x, y);
		return (*room);
	}
	tmp = *room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_room(name, x, y);
	return (tmp->next);
}

void	add_process(t_room **room, char *line)
{
	char	**assign;
	int		i;

	i = 0;
	assign = ft_strsplit(line, ' ');
	*room = create_room(assign[0],
	ft_atoi(assign[1]), ft_atoi(assign[2]));
	while (assign[i])
	{
		free(assign[i]);
		i++;
	}
	free(assign);
}

int		hashtags(t_graph **head, char *line)
{
	int i;

	i = 0;
	if (ft_strstr(line, "##start"))
	{
		free(line);
		line = read_line();
		add_process(&((*head)->start), line);
		i = 1;
	}
	if (ft_strstr(line, "##end"))
	{
		free(line);
		line = read_line();
		add_process(&((*head)->end), line);
		i = 1;
	}
	if (line[0] == '#')
	{
		i = 1;
		free(line);
	}
	return (i == 0 ? 0 : 1);
}

t_room	*room_process(t_room **room , char	**assign)
{
	return (add_room(room, assign[0], 
	ft_atoi(assign[1]), ft_atoi(assign[2])));
}
