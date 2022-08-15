/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:03:44 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/21 05:09:43 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	display(char **gameboard, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		ft_putstr(gameboard[i]);
		ft_putchar('\n');
		i++;
	}
}

void	usasge_error(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit [fille_name]\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	char	*s;
	int		***tetrisboard;
	char	**gameboard;
	t_cord	n;

	usasge_error(argc);
	if (reader(&s, argv[1]) == 0)
	{
		ft_putstr("error\n");
		exit(0);
	}
	n.y = count_tetrominos(s);
	tetrisboard = malloctetrisboard(n.y);
	tetrishredder(s, &tetrisboard, n.y);
	n.x = gameboardsize(n.y);
	gameboard = mallocgameboard(n.x);
	while (solveit(&gameboard, tetrisboard, n) == 0)
	{
		free_gameboard(&gameboard, n.x);
		gameboard = mallocgameboard(++n.x);
	}
	display(gameboard, n.x);
	free_gameboard(&gameboard, n.x);
	freetetrisboard(&tetrisboard, n.y);
	return (0);
}
