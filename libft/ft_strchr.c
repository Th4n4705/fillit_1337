/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 03:53:15 by masali            #+#    #+#             */
/*   Updated: 2018/10/20 04:45:51 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*ps;
	size_t			l;

	l = ft_strlen(s);
	ps = (unsigned char*)s;
	while (*ps)
	{
		if ((unsigned char)c == *ps)
			return ((void *)ps);
		ps++;
	}
	if (c == '\0')
		return ((char *)ps);
	return (NULL);
}
