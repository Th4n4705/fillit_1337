/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 19:03:31 by masali            #+#    #+#             */
/*   Updated: 2018/10/31 19:06:30 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int		i;
	size_t	k;

	k = 0;
	i = 0;
	while (k < ft_strlen(s))
	{
		if (s[k] != c)
			if (s[k + 1] == c || s[k + 1] == '\0')
				i++;
		k++;
	}
	return (i);
}

static char	**ft_alloue_nb_char(char **res, char const *s, char c)
{
	int		j;
	size_t	k;

	k = 0;
	j = 0;
	while (k < ft_strlen(s))
	{
		if (s[k] != c)
		{
			j++;
			if (s[k + 1] == c || s[k + 1] == '\0')
			{
				*res = (char *)malloc(sizeof(char) * (j + 1));
				res++;
				j = 0;
			}
		}
		k++;
	}
	return (res);
}

static char	**ft_remplir_tab(char **res, char const *s, char c)
{
	int		i;
	int		j;
	size_t	k;

	k = 0;
	i = 0;
	j = 0;
	while (k < ft_strlen(s))
	{
		if (s[k] != c)
		{
			res[i][j] = s[k];
			j++;
			if (s[k + 1] == c || s[k + 1] == '\0')
			{
				res[i][j] = '\0';
				i++;
				j = 0;
			}
		}
		k++;
	}
	res[i] = 0;
	return (res);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;

	if (!s)
		return (NULL);
	i = ft_nb_words(s, c);
	if (!(res = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	res = ft_alloue_nb_char(res, s, c);
	res -= i;
	res = ft_remplir_tab(res, s, c);
	return (res);
}
