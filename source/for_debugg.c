/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_debugg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 21:20:29 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/09 21:21:13 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display(t_graph *graph)
{
	t_room *tmp;
	t_link *temp;

	tmp = graph->begining;
	while (tmp)
	{
		ft_printf("%s : ", tmp->name);
		temp = tmp->link;
		while (temp)
		{
			ft_printf("%s ", temp->room->name);
			temp = temp->next;
		}
		ft_printf("\n");
		tmp = tmp->next;
	}
}

void	display_multi(t_multi *multi)
{
	t_paths	*tmp;
	t_path	*temp;

	tmp = multi->paths;
	while (tmp)
	{
		temp = tmp->path;
		while (temp)
		{
			ft_printf("|%s| ", temp->room->name);
			temp = temp->next;
		}
		ft_printf("\n\n");
		tmp = tmp->next;
	}
}