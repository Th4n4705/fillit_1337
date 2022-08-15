/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:43:07 by masali            #+#    #+#             */
/*   Updated: 2018/10/26 15:24:09 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ch1;
	char	*ch2;

	i = 0;
	ch1 = (char *)haystack;
	ch2 = (char *)needle;
	if (*ch1 == '\0' && *ch2 == '\0')
		return (ch1);
	while (ch1[i] != '\0' && i < len)
	{
		j = 0;
		while (ch1[i + j] == ch2[j] && ch2[j] != '\0' && (i + j) < len)
			j++;
		if (ch2[j] == '\0')
			return (ch1 + i);
		i++;
	}
	return (NULL);
}
