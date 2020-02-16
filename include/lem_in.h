/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 17:34:00 by oaghzaf           #+#    #+#             */
/*   Updated: 2020/02/16 23:05:32 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H
#include "../source/ft_printf/headers/ft_printf.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "ft_checker.h"

typedef struct  s_data
{
    char        *line;
    struct  s_data     *next;
}               t_data;

typedef struct  s_lemin
{
    int         last_r;
	int			e;
	int			s;
    struct  s_data      *data;
}               t_lemin;

typedef struct	s_link	t_link;

typedef struct	s_info
{
	long		ants;
	int		instructions;
}				t_info;

typedef struct		s_room
{
	char			*name;
	int				cord[2];
	t_link			*link;
	int				visited;
	int				capacity;
	struct s_room	*next;
	struct s_room	*previous;
}					t_room;

typedef struct		s_graph
{
	t_room	*start;
	t_room	*end;
	t_room	*begining;
}					t_graph;

struct	s_link
{
	t_room	*room;
	t_link	*next;
	int		flow;
};

typedef struct	s_path
{
	t_room			*room;
	int				ant;
	struct s_path	*next;
}				t_path;

typedef struct	s_queue
{
	t_room			*room;
	struct s_queue	*next;
}				t_queue;

typedef struct	s_paths
{
	t_path			*path;
	int				ants;
	int				length;
	struct s_paths	*next;
}				t_paths;

typedef struct	s_multi
{
	t_paths			*paths;
	struct s_multi	*next;
}				t_multi;

typedef struct	s_ants_farm
{
	t_paths				*path;
	int					ants;
	struct s_ants_farm	*next;
}				t_ants_farm;



t_room	*create_room(char *name, int x, int y);
t_room	*add_room(t_room **room, char *name, int x, int y);
void	add_start_end(t_room *room, t_room *start, t_room *end);
t_link	*creat_link(t_room *room);
t_room	*find_room(char *name, t_room *room);
void	link_add(t_room *room, t_room *to_add);
void	add_process(t_room **room, char *line);
char	*read_line(void);
void	link_process(t_room **room, char *line);
t_room	*room_process(t_room **r, char **assign);
int		bfs(t_graph *graph);
void	reset(t_room *room);
void	update_flow(t_room *one, t_room *two, t_graph *graph);
void	add_path(t_path *path, t_room *room);
t_path	*creat_path(t_room *room);
void	add_paths(t_paths *paths, t_path *path);
t_paths	*creat_paths(t_path *path);
void	free_two(char **tab);
void	links_core(char *line, t_room **holder, t_room **two, t_room **room);
void	creating_path(t_link **tmp, t_path **path);
void	add_multi(t_multi *multi, t_paths *paths);
t_multi	*creat_multi(t_paths *paths);
t_paths	*get_paths(t_graph *graph);
void	free_queue(t_queue *queue);
void	init(t_info *info, t_graph *head, t_lemin *l);
void	the_core(t_graph *head, t_multi **multi);
t_multi		*optimal_path(t_multi *multi, t_info *info);
int		ants_path(t_multi *multi, t_info *info);
int		path_length(t_path *path);
int		paths_length(t_paths *paths);
void	bubble_sort(t_paths *paths);
t_paths	*sort_paths(t_paths *paths);
void	add_rest(t_paths *paths, int rest, t_info *info);
void	loop_path(t_paths *paths, t_info *info, t_graph *graph);
void	free_room(t_room *room);
void	free_path(t_path *path);
void	free_paths(t_paths *paths);
void	free_multi(t_multi *multi, t_lemin *l);


/*
** CHECKING FILE VALIDATION FUNCTIONS
*/
int			get_next_line(const int fd, char **line);
int			check_validation(t_lemin *l, t_graph *g ,t_info *info);
t_room		*add_torooms(t_room **rooms ,char *line);
long int    long_atoi(const char *str);
void        free_data(t_data *data);
void        free_lemin(t_lemin *l);
int         is_egnored(char *str);
int         is_empty(char *str);
void        get_rooms_links(char *line, t_lemin *l, t_graph *g);
t_room      *add_torooms(t_room **rooms ,char *line);
int         link_rooms(t_room *rooms, char *line);
void        get_start_end(char *line, t_lemin *l, int *s, int e, t_graph *g);
void        exit_error(t_lemin *l, char *line);
int         n_valid(char *str);
void		free_2d_str(char **str);
/*
** CHECKING FILE VALIDATION FUNCTIONS ENDED
*/
# endif

