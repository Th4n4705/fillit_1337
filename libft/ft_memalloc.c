/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 16:14:57 by masali            #+#    #+#             */
/*   Updated: 2018/10/29 16:29:47 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mal;
	size_t	i;

	i = 0;
	mal = (char *)malloc(size);
	if (mal == NULL)
		return (NULL);
	while (i < size)
	{
		mal[i] = 0;
		i++;
	}
	return (mal);
}
