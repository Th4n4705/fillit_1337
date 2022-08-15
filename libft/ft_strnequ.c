/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 21:06:27 by masali            #+#    #+#             */
/*   Updated: 2018/10/29 21:22:18 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (*s1 == *s2 && *s1 && i < n)
	{
		i++;
		s1++;
		s2++;
	}
	if (i == n || (*s1 == '\0' && *s2 == '\0'))
		return (1);
	return (0);
}