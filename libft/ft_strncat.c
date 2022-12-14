/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 20:28:28 by masali            #+#    #+#             */
/*   Updated: 2018/10/19 21:05:54 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t l;
	size_t i;

	i = 0;
	l = ft_strlen(s1);
	while (i < n && s2[i] != '\0')
	{
		s1[l + i] = s2[i];
		i++;
	}
	s1[l + i] = '\0';
	return (s1);
}
