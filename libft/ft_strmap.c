/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 19:12:03 by masali            #+#    #+#             */
/*   Updated: 2018/10/29 20:32:04 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	new = (char *)malloc(ft_strlen(s) * sizeof(char) + 1);
	if (new == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
