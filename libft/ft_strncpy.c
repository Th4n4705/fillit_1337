/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 18:11:21 by masali            #+#    #+#             */
/*   Updated: 2018/10/17 19:27:29 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int end;
	int l;

	l = (int)len;
	i = 0;
	end = 0;
	while (i < l)
	{
		if (end == 0 && src[i] != '\0')
			dst[i] = src[i];
		else
			end = 1;
		if (end == 1)
			dst[i] = '\0';
		i++;
	}
	return (dst);
}
