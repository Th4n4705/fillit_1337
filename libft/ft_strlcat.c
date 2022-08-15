/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 22:32:05 by masali            #+#    #+#             */
/*   Updated: 2018/10/20 03:34:46 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lsrc;
	size_t ldst;
	size_t i;

	i = 0;
	lsrc = ft_strlen(src);
	ldst = ft_strlen(dst);
	if (size <= ldst)
		return (lsrc + size);
	while (*dst)
		dst++;
	while (i < (size - ldst) - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (lsrc + ldst);
}
