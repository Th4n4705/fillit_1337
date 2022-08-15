/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twakrim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 16:18:50 by twakrim           #+#    #+#             */
/*   Updated: 2019/05/20 15:18:43 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fourchars_help(int *l, int *c, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if ((s[i] != '.' && s[i] != '#' && s[i] != '\n')
				|| ((*c) > 4 || ((*c) < 4 && s[i] == '\n' && (*l) != 5))
				|| ((*l) == 5 && (*c) != 0) || ((*l) == 5 && s[i] != '\n'))
			return (0);
		else if ((*l) == 5 && (*c) == 0 && s[i - 1] == '\n')
			(*l) = 0;
		if (s[i] != '\n')
			(*c)++;
		else
		{
			(*c) = 0;
			(*l)++;
		}
		i++;
	}
	if (!(s[i] == '\0' && s[i - 1] == '\n'
				&& (s[i - 2] == '#' || s[i - 2] == '.')))
		return (0);
	return (1);
}

int		fourchars(char *s)
{
	int		c;
	int		l;

	c = 0;
	l = 1;
	return (fourchars_help(&l, &c, s));
}

int		count_tetrominos(char *s)
{
	int		tetris;
	int		i;

	tetris = 0;
	i = 0;
	while (s[i])
	{
		if (s[i + 1] == '\n' && s[i] == '\n')
			tetris++;
		i++;
	}
	if (s[i - 1] == '\n')
		tetris += 1;
	if (tetris < 1 || tetris > 26)
		return (0);
	return (tetris);
}

int		valstring(char *s)
{
	if (fourchars(s) && count_tetrominos(s) != 0)
		return (1);
	return (0);
}
