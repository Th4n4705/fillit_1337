/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 02:00:44 by masali            #+#    #+#             */
/*   Updated: 2018/10/31 02:22:20 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (s == NULL)
		return (NULL);
	sub = (char*)malloc(len + 1);
	if (!sub)
		return (NULL);
	s = s + start;
	ft_strncpy(sub, s, len);
	sub[len] = '\0';
	return (sub);
}
