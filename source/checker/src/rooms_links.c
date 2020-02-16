/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:45:43 by llachgar          #+#    #+#             */
/*   Updated: 2020/02/16 11:52:08 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void get_rooms_links(char *line, t_lemin *l, t_graph *g)
{
    if (ft_strrchr(line, '-'))
    {
        l->last_r = 1;
        if (!link_rooms(g->begining, line))
            exit_error(l);
    }
    else if(l->last_r || !add_torooms(&g->begining, line))
    {
        exit_error(l);
    }
}

t_room *add_torooms(t_room **rooms ,char *line)
{
    char **tab;
    t_room *tmp;
    int i;

    i = 0;
    tab = ft_strsplit(line, ' ');
    while (tab && tab[i])
        i++;
    if (i != 3 || find_room(tab[0], *rooms))
    {
        //free 2d array
        return (NULL);
    }
    tmp = room_process(rooms, tab);
    // free 2d table
    // init begin
    return (tmp);
}

int link_rooms(t_room *rooms, char *line)
{
    char **tab;
    t_room	*holder;
	t_room	*two;
    int i;
    //TODO: FREE
    i = 0;
    tab = ft_strsplit(line, '-');
    while (tab && tab[i])
        i++;
    if (i != 2)
        return (0);
    holder = find_room(tab[0], rooms);
    two  = find_room(tab[1], rooms);
    if (!holder || !two)
        return (0);
    if (!holder->link)
        holder->link = creat_link(two);
    else
        link_add(holder, two);
    if (!two->link)
        two->link = creat_link(holder);
    else
        link_add(two, holder);
    return (1);
}

void get_start_end(char *line, t_lemin *l, int *s, int e, t_graph *g)
{
    if (*s != 0 || l->last_r)
    {
        free(line);
        exit_error(l);
    }
    free(line);
    line = NULL;
    while (get_next_line(0, &line) > 0)
    {
        if (is_empty(line) || n_valid(line))
        {
            free(line);
            exit_error(l);
        }
        else if (!is_egnored(line))
            break ;
    }
    if (!e)
       g->start = add_torooms(&g->begining, line);
    else
       g->end = add_torooms(&g->begining, line);
    *s = 1;
}