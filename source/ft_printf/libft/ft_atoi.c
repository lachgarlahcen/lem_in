/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaghzaf <oaghzaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 23:06:16 by oaghzaf           #+#    #+#             */
/*   Updated: 2019/12/11 22:31:39 by oaghzaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	ans;
	int	sign;

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
