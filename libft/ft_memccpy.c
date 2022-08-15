/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:11:25 by masali            #+#    #+#             */
/*   Updated: 2018/10/18 20:17:50 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*pdst;
	unsigned char	*psrc;
	unsigned char	pc;

	pc = (unsigned char)c;
	pdst = (unsigned char*)dst;
	psrc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		pdst[i] = psrc[i];
		if (psrc[i] == pc)
		{
			return (pdst + i + 1);
		}
		i++;
	}
	return (NULL);
}
