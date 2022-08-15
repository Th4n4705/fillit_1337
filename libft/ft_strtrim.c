/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 02:35:42 by masali            #+#    #+#             */
/*   Updated: 2018/10/31 18:31:12 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*strm;
	unsigned int	i;
	unsigned int	l;

	i = 0;
	if (!s)
		return (NULL);
	l = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n'
			|| s[i] == '\t') && s[i] != '\0')
		i++;
	if (i == l)
		return (ft_strnew(1));
	while (s[l - 1] == ' ' || s[l - 1] == '\n'
			|| s[l - 1] == '\t')
		l--;
	if (!(strm = (char *)malloc(l - i + 1)))
		return (NULL);
	else
		return (strm = ft_strsub(s, i, l - i));
}
