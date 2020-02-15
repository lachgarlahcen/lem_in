/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:21:47 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/15 09:32:22 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		update_flow(t_room *one, t_room *two, t_graph *graph)
{
	t_link *first;
	t_link *second;

	first = one->link;
	second = two->link;
	while (first->room != two)
		first = first->next;
	if (first->flow == 1 && first->room !=
	graph->start && first->room != graph->end)
	{
		first->flow = 2;
		first->room->capacity = 1;
	}
	else
		first->flow = 1;
	while (second->room != one)
		second = second->next;
	if (second->flow == 1 && second->room !=
	graph->start && second->room != graph->end)
	{
		second->flow = 0;
		second->room->capacity = 1;
	}
	else
		second->flow = 1;
}

t_queue		*creat_queue(t_room *room)
{
	t_queue *queue;

	queue = malloc(sizeof(t_queue));
	queue->room = room;
	queue->next = NULL;
	return (queue);
}

void		add_queue(t_queue *queue, t_room *room)
{
	t_queue *tmp;

	tmp = queue;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = creat_queue(room);
}

void		main_conditions(t_link **tmp, t_queue **queue,
t_link **temp, t_graph *graph)
{
	(void)graph;
	if (!(*tmp)->room->visited && (((*tmp)->room->capacity
			&& (*tmp)->flow == 2) || !(*tmp)->room->capacity))
	{
		add_queue(*queue, (*tmp)->room);
		(*tmp)->room->visited = 1;
		(*tmp)->room->previous = (*queue)->room;
	}
	if ((*tmp)->room->capacity && (*tmp)->flow && !(*tmp)->room->visited)
	{
		*temp = (*tmp)->room->link;
		while (*temp)
		{
			if ((*temp)->flow == 2)
			{
				add_queue(*queue, (*temp)->room);
				(*temp)->room->visited = 1;
				(*temp)->room->previous = (*tmp)->room;
			}
			*temp = (*temp)->next;
		}
		(*tmp)->room->previous = (*queue)->room;
	}
}

int			bfs(t_graph *graph)
{
	t_queue *queue;
	t_link	*tmp;
	t_link	*temp;
	t_queue *hold;

	queue = creat_queue(graph->start);
	hold = queue;
	queue->room->visited = 1;
	while (queue)
	{
		tmp = queue->room->link;
		while (tmp)
		{
			main_conditions(&tmp, &queue, &temp, graph);
			if (tmp->room == graph->end)
				return (1);
			tmp = tmp->next;
		}
		queue = queue->next;
	}
	free_queue(hold);
	return (0);
}
