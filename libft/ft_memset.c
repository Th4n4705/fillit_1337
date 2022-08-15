/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:12:13 by masali            #+#    #+#             */
/*   Updated: 2018/10/31 19:12:16 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ch;

	ch = (char*)b;
	i = 0;
	while (i < len)
	{
		ch[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
