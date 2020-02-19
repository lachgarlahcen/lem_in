/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:32:38 by llachgar          #+#    #+#             */
/*   Updated: 2020/02/16 14:50:35 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

void	init(t_info *info, t_graph *head, t_lemin *l)
{
	l->data = NULL;
    l->last_r = 0;
    l->e = 0;
    l->s = 0;
	head->start = NULL;
	head->end = NULL;
	head->begining = NULL;
	info->instructions = 0;
	info->ants  = 0;
}

long check_ant_num(char *line)
{
    long i;
    i = 0;
    while (line[i] && line[i] >= '0' && line[i] <= '9')
        i++;
    if(line[i] == '\0' && i != 0)
    {
        i = long_atoi(line);
        return (i);
    }
    return (-1);
}

void  exit_error(t_lemin *l, char *line)
{
    free_lemin(l);
    if (line)
        free(line);
    ft_printf("ERROR\n");
    exit(0);
}

t_data *create_data(t_data *data, char *line)
{
    t_data *tmp;
    if (!(tmp = (t_data *)malloc(sizeof(t_data))))
        return (NULL);
    tmp->next = data;
    tmp->line = ft_strdup(line);
    return (tmp);
}
void swap_strings(char **str1, char **str2)
{
    char *tmp;

    tmp = *str1;
    *str1 = *str2;
    *str2 = tmp;
}
int check_validation(t_lemin *l, t_graph *g, t_info *i)
{
    char *line;

    line = NULL;
    get_next_line(0, &line);
    if (!line || (i->ants = check_ant_num(line)) < 0 || i->ants > 2147483647)
        exit_error(l, line);
    free(line);
    while (get_next_line(0, &line) > 0)
    {
        if (is_empty(line))
            break ;
        if (n_valid(line))
            exit_error(l, line);
        l->data = create_data(l->data,line);
        if (is_egnored(line))
            continue ;
        else if (ft_strequ(line, "##start"))
            get_start_end(line, l, &l->s, 1, g);
        else if (ft_strequ(line, "##end"))
            get_start_end(line, l, &l->e, 0, g);
        else
            get_rooms_links(line, l, g);
    }
    if (!g->start|| !g->end)
        exit_error(l, line);
    swap_strings(&(g->start->name), &(g->end->name));
    return (1);
}