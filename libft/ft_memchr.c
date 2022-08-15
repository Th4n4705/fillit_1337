/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:25:48 by masali            #+#    #+#             */
/*   Updated: 2018/10/20 05:27:59 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	i = 0;
	ps = (unsigned char*)s;
	while (i < n)
	{
		if ((unsigned char)c == *ps)
			return ((void *)ps);
		i++;
		ps++;
	}
	return (NULL);
}
