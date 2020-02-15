/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:21:27 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 20:20:40 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

static void	rest_case(t_multiplication *args, int *i, int *j, int *rest)
{
	if (*rest != 0 && *j == args->str1_length)
	{
		args->result[*i][*j + *i] = *rest + 48;
		(*j)++;
	}
}

void		multi_algo(t_multiplication *args)
{
	int	i;
	int	j;
	int	rest;

	i = -1;
	rest = 0;
	while (++i < args->str2_length)
	{
		args->result[i] = ft_strnew(args->str1_length + 1 + i);
		add_zero(&args->result[i], i);
		j = 0;
		rest = 0;
		while (j < args->str1_length)
		{
			args->result[i][j + i] = ((args->str1[j] - 48) *
					(args->str2[i] - 48) + rest) % 10 + 48;
			rest = ((args->str1[j] - 48) * (args->str2[i] - 48) + rest) / 10;
			j++;
			rest_case(args, &i, &j, &rest);
		}
		args->result[i][j + i] = '\0';
		reverse_str(&args->result[i]);
	}
}

char		*addition_part(t_multiplication *args)
{
	char	*free_dump;
	char	*dump;
	int		i;

	dump = ft_strdup(args->result[0]);
	i = 1;
	while (i < args->str2_length && args->result[i - 1] != NULL)
	{
		free_dump = dump;
		dump = addition(args->result[i], free_dump);
		free(free_dump);
		i++;
	}
	return (dump);
}

static void	free_multiplication(t_multiplication *args)
{
	int	i;

	i = 0;
	while (args->result[i] != NULL)
	{
		free(args->result[i]);
		i++;
	}
	free(args->result);
}

char		*multiplication(char *str1, char *str2)
{
	t_multiplication	args;
	char				*result;
	char				*dump;

	if (!strcmp(str1, "0") || !strcmp(str2, "0"))
		return (ft_strdup("0"));
	args.point = 0;
	reverse_str(&str1);
	reverse_str(&str2);
	args.str1 = without_point(str1, &args.point);
	args.str2 = without_point(str2, &args.point);
	swap_str(&args.str1, &args.str2);
	args.str1_length = ft_strlen(args.str1);
	args.str2_length = ft_strlen(args.str2);
	args.result = (char **)malloc((args.str2_length + 1) * sizeof(char *));
	args.result[args.str2_length] = NULL;
	multi_algo(&args);
	result = addition_part(&args);
	reverse_str(&result);
	dump = result;
	result = add_point(dump, args.point);
	free(dump);
	reverse_str(&result);
	free_multiplication(&args);
	return (result);
}
