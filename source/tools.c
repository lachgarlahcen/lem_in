/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:53:45 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/03 11:48:56 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	reset(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		tmp->visited = 0;
		tmp = tmp->next;
	}
}

void	free_two(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_queue(t_queue *queue)
{
	t_queue	*tmp;

	while ((tmp = queue))
	{
		free(tmp);
		queue = queue->next;
	}
}

void	add_start_end(t_room *room, t_room *start, t_room *end)
{
	t_room	*tmp;

	tmp = room;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = start;
	start->next = end;
}
