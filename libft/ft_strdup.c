/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 22:58:27 by masali            #+#    #+#             */
/*   Updated: 2018/10/16 23:41:56 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cop;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	cop = malloc(sizeof(char) * (len + 1));
	if (cop == NULL)
		return (NULL);
	while (i <= len)
	{
		*cop = *s1;
		i++;
		cop++;
		s1++;
	}
	cop = cop - (len + 1);
	return (cop);
}
