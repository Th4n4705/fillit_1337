/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:15:52 by masali            #+#    #+#             */
/*   Updated: 2018/10/26 14:46:25 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	char	*ch1;
	char	*ch2;

	i = 0;
	ch1 = (char *)haystack;
	ch2 = (char *)needle;
	if (*ch1 == '\0' && *ch2 == '\0')
		return (ch1);
	while (ch1[i] != '\0')
	{
		j = 0;
		while (ch1[i + j] == ch2[j] && ch2[j] != '\0')
			j++;
		if (ch2[j] == '\0')
			return (ch1 + i);
		i++;
	}
	return (NULL);
}
