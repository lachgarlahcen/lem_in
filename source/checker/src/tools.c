/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llachgar <llachgar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 20:30:59 by llachgar          #+#    #+#             */
/*   Updated: 2020/02/15 09:20:26 by llachgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_checker.h"

long int        long_atoi(const char *str)
{
	long	int		ans;
	int				sign;

	sign = 1;
	while (*str == '\n' || *str == '\t' || *str == ' ' ||
			*str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	ans = 0;
	while (*str != '\0' && (*str >= 48 && *str <= 57))
	{
		ans = ans * 10;
		ans = ans + *str - 48;
		str++;
	}
	return (ans * sign);
}

void free_data(t_data *data)
{
    t_data *tmp;

    while (data)
    {
        tmp = data;
        data = data->next;
        free(tmp);
    }
}

void free_lemin(t_lemin *l)
{
    free_data(l->data);
}

int is_egnored(char *str)
{
    if (str[0] == '#' && !(!ft_strcmp(str, "##start") || !ft_strcmp(str, "##end")))
        return (1);
    return (0);
}
int n_valid(char *str)
{
	if (str[0] == 'L')
        return (1);
	return (0);
}

int is_empty(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (1);
    while (str[i] && str[i] == ' ')
        i++;
    if (str[i] != '\0')
        return (0);
    return (1);
}