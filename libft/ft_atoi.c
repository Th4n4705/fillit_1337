/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 15:32:53 by masali            #+#    #+#             */
/*   Updated: 2018/10/25 13:07:05 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ispchar(char c)
{
	if (c == ' ' || c == '\0' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int num;
	int sin;

	sin = 1;
	num = 0;
	while (ft_ispchar(*str))
		str++;
	if (str[0] == '-')
	{
		sin = -1;
		str++;
	}
	else if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sin);
}
