/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 21:35:03 by masali            #+#    #+#             */
/*   Updated: 2018/10/18 22:06:48 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*pdst;
	char	*psrc;

	psrc = (char*)src;
	pdst = (char*)dst;
	if (psrc > pdst)
		pdst = ft_memcpy(pdst, psrc, len);
	else
		while (len--)
			*(pdst + len) = *(psrc + len);
	return (pdst);
}
