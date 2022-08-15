/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 05:20:12 by masali            #+#    #+#             */
/*   Updated: 2018/10/20 05:21:24 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	l;
	char	pc;

	pc = (char)c;
	l = ft_strlen(s);
	while ((int)l >= 0)
	{
		if (s[l] == pc)
			return ((char *)(s + l));
		l--;
	}
	return (NULL);
}
