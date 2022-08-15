/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:44:16 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/21 05:10:29 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		infopoint(char tetris[4][4], int ***infotetris)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			if (tetris[i][j] == '#')
			{
				(*infotetris)[k][0] = i;
				(*infotetris)[k][1] = j;
				k++;
			}
			j++;
		}
		i++;
	}
	align(infotetris);
}

void		valid_tetrisshredder(char tetris[4][4], int tetrinum
		, int ****tetriboard)
{
	if (all_valid(tetris))
		tetristoboard(tetrinum, tetriboard, tetris);
	else
	{
		ft_putstr("error\n");
		exit(0);
	}
}

void		loop_tetrisshredder(t_cord *t, char *file, char tetris[4][4])
{
	int		z;

	z = 0;
	(*t).y = 0;
	while ((*t).y <= 20)
	{
		if (file[(*t).x + (*t).y] == '#' || file[(*t).x + (*t).y] == '.')
			tetris[z][(*t).y % 5] = file[(*t).x + (*t).y];
		else if (file[(*t).x + (*t).y] == '\n')
			z++;
		(*t).y++;
	}
}

int			tetrishredder(char *file, int ****tetriboard, int nbr_tet)
{
	char	tetris[4][4];
	t_cord	t;
	int		tetrinum;

	tetrinum = 0;
	if (!valstring(file))
	{
		ft_putstr("error\n");
		exit(0);
	}
	t.x = 0;
	while (file[t.x] != '\0' && tetrinum < nbr_tet)
	{
		loop_tetrisshredder(&t, file, tetris);
		valid_tetrisshredder(tetris, tetrinum, tetriboard);
		tetrinum++;
		t.x = t.x + t.y;
	}
	free(file);
	return (1);
}

int			gameboardsize(int numtetris)
{
	int		i;

	i = 2;
	while (i * i < numtetris * 4)
		i++;
	return (i);
}
