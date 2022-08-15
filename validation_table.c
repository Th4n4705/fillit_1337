/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:18:23 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/20 15:18:52 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fourlines(char fourln[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (fourln[i][j] != '\n')
		{
			j++;
		}
		if (j != 4)
			return (0);
		i++;
	}
	return (1);
}

int		valid_tab_caracter(char tetris[4][4])
{
	int		i;
	int		j;
	int		ndot;
	int		nhach;

	i = 0;
	ndot = 0;
	nhach = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (tetris[i][j] == '#')
				nhach++;
			else if (tetris[i][j] == '.')
				ndot++;
			j++;
		}
		i++;
	}
	if (ndot == 12 && nhach == 4)
		return (1);
	return (0);
}

void	validshape_helper(int *nhashtags, int *links, char tetris[4][4])
{
	int		i;
	int		j;

	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (tetris[i][j] == '#')
				(*nhashtags)++;
			if (j + 1 <= 3 && tetris[i][j] == '#' && tetris[i][j + 1] == '#')
				(*links)++;
			if (i + 1 <= 3 && tetris[i][j] == '#' && tetris[i + 1][j] == '#')
				(*links)++;
			j++;
		}
		i++;
	}
}

int		valid_shape(char tetris[4][4])
{
	int		links;
	int		nhashtags;

	links = 0;
	nhashtags = 0;
	validshape_helper(&nhashtags, &links, tetris);
	if (nhashtags == 4 && (links == 3 || links == 4))
		return (1);
	return (0);
}

int		all_valid(char tetris[4][4])
{
	if ((valid_shape(tetris) != 0) && (valid_tab_caracter(tetris) != 0))
		return (1);
	return (0);
}
