/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_extra_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 04:59:45 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/20 15:18:00 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		tetristoboard(int indice, int ****tetriboard, char tetris[4][4])
{
	int		i;
	int		j;
	int		**tetrispoint;

	i = 0;
	tetrispoint = (int **)malloc(sizeof(int *) * 4);
	while (i <= 3)
		tetrispoint[i++] = (int *)malloc(sizeof(int) * 2);
	i = 0;
	infopoint(tetris, &tetrispoint);
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			tetriboard[0][indice][i][j] = tetrispoint[i][j];
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= 3)
		free(tetrispoint[i++]);
	free(tetrispoint);
}

void		align_helper(int ***infotetris, int mini, int minj)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			if (j == 0)
				(*infotetris)[i][j] = (*infotetris)[i][j] - mini;
			if (j == 1)
				(*infotetris)[i][j] = (*infotetris)[i][j] - minj;
			j++;
		}
		i++;
	}
}

void		align(int ***infotetris)
{
	int		mini;
	int		minj;
	int		i;

	i = 0;
	mini = 3;
	minj = 3;
	while (i <= 3)
	{
		if ((*infotetris)[i][0] < mini)
			mini = (*infotetris)[i][0];
		if ((*infotetris)[i][1] < minj)
			minj = (*infotetris)[i][1];
		i++;
	}
	align_helper(infotetris, mini, minj);
}
