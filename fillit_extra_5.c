/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 19:27:37 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/20 15:18:17 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			***malloctetrisboard(int z)
{
	int		i;
	int		j;
	int		***tetrisboard;

	i = 0;
	tetrisboard = (int ***)malloc(sizeof(int **) * (z + 1));
	while (i < z)
	{
		tetrisboard[i] = (int **)malloc(sizeof(int *) * 4);
		j = 0;
		while (j < 4)
		{
			tetrisboard[i][j] = (int *)malloc(sizeof(int) * 2);
			j++;
		}
		i++;
	}
	tetrisboard[i] = NULL;
	return (tetrisboard);
}

char		**mallocgameboard(int x)
{
	int		i;
	char	**gameboard;
	int		j;

	i = 0;
	gameboard = (char **)malloc(sizeof(char*) * (x + 1));
	while (i < x)
	{
		gameboard[i] = (char *)malloc(sizeof(char) * (x + 1));
		j = 0;
		while (j < x)
			gameboard[i][j++] = '.';
		gameboard[i][x] = '\0';
		i++;
	}
	gameboard[x] = "\0";
	return (gameboard);
}

void		freetetrisboard(int ****tetrisboard, int numboftet)
{
	int		i;
	int		x;

	i = numboftet - 1;
	while (i >= 0)
	{
		x = 0;
		while (x < 4)
		{
			free(tetrisboard[0][i][x]);
			x++;
		}
		free(tetrisboard[0][i]);
		i--;
	}
	free(tetrisboard[0]);
}

void		free_gameboard(char ***gameboard, int x)
{
	int		i;

	i = 0;
	while (i < x)
		free((*gameboard)[i++]);
	free(*gameboard);
}
