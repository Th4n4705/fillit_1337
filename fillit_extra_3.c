/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_extra_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:24:15 by masali            #+#    #+#             */
/*   Updated: 2019/05/20 15:17:31 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		help_issafe2helper(t_cord *s, t_cord t, char ***gameboard, int *c)
{
	(*s).x = t.x;
	(*s).y = t.y;
	(*c)++;
	(*gameboard)[t.x][t.y] = '.';
}

int			issafe2_helper(t_cord *s, char ***gameboard, int boardsize
		, int tetnum)
{
	t_cord	t;
	int		c;

	t.x = 0;
	c = 0;
	while (t.x < boardsize)
	{
		t.y = 0;
		while (t.y < boardsize)
		{
			if (c == 0 && (*gameboard)[t.x][t.y] == tetnum + 65)
				help_issafe2helper(s, t, gameboard, &c);
			else if ((*gameboard)[t.x][t.y] == tetnum + 65)
			{
				c++;
				(*gameboard)[t.x][t.y] = '.';
			}
			t.y++;
		}
		t.x++;
	}
	return (c);
}

t_cord		is_safe2(char ***gameboard, int boardsize, int tetnum)
{
	t_cord	s;
	int		c;

	c = issafe2_helper(&s, gameboard, boardsize, tetnum);
	if (c < 1)
	{
		s.x = -99;
		s.y = -99;
	}
	return (s);
}

t_cord		issafe_helper(char ***gameboard, int **infotetris, t_cord t
		, t_safe s)
{
	int		i;
	int		j;

	i = s.i;
	while (i < s.boardsize)
	{
		j = 0;
		if (s.ver == 1)
		{
			j = t.y - infotetris[0][1] + 1;
			s.ver = 0;
		}
		while (j < s.boardsize)
		{
			t.x = i;
			t.y = j;
			if (safe_helper(t, *gameboard, infotetris, s.boardsize))
				return (t);
			j++;
		}
		i++;
	}
	t.x = -99;
	t.y = -99;
	return (t);
}

t_cord		is_safe(char ***gameboard, int **infotetris, int boardsize
		, int tetnum)
{
	t_cord	t;
	t_safe	s;

	s.i = 0;
	s.ver = 1;
	t = is_safe2(gameboard, boardsize, tetnum);
	if (t.x != -99 && t.y != -99)
		s.i = t.x;
	else
		s.ver = 0;
	s.boardsize = boardsize;
	s.tetnum = tetnum;
	return (issafe_helper(gameboard, infotetris, t, s));
}
