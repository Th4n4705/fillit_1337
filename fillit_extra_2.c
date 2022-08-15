/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_extra_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:33:12 by masali            #+#    #+#             */
/*   Updated: 2019/05/20 18:41:24 by twakrim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			reader(char **s, char *filename)
{
	int		fd;
	int		ret;
	int		len;
	char	*line;
	char	*temp;

	len = 0;
	*s = ft_strdup("");
	(fd = open(filename, O_RDONLY));
	while ((ret = get_tetris_lines(fd, &line)) > 0)
	{
		temp = *s;
		*s = ft_strjoin(*s, line);
		free(line);
		free(temp);
	}
	len = ft_strlen(*s);
	if (ret < 0 || len > 545 || len == 0)
		return (0);
	free(line);
	return (1);
}

int			safe_helper(t_cord s, char **gameboard, int **inf_t, int boardsize)
{
	if (s.x + inf_t[0][0] >= boardsize || s.y + inf_t[0][1] >= boardsize
			|| s.x + inf_t[1][0] >= boardsize || s.y + inf_t[1][1] >=
			boardsize || s.x + inf_t[2][0] >= boardsize || s.y + inf_t[2][1]
			>= boardsize || s.x + inf_t[3][0] >= boardsize
			|| s.y + inf_t[3][1] >= boardsize)
		return (0);
	if (gameboard[s.x + inf_t[0][0]][s.y + inf_t[0][1]] == '.' &&
			gameboard[s.x + inf_t[1][0]][s.y + inf_t[1][1]] == '.' &&
			gameboard[s.x + inf_t[2][0]][s.y + inf_t[2][1]] == '.' &&
			gameboard[s.x + inf_t[3][0]][s.y + inf_t[3][1]] == '.')
		return (1);
	return (0);
}

int			count_tet2(int ***tetboard)
{
	int		i;

	i = 0;
	while (tetboard[i] != NULL)
		i++;
	return (i);
}

void		put_tet(char ***gameboard, int **inf_t, t_cord pos, int tetr_ind)
{
	(*gameboard)[pos.x + inf_t[0][0]][pos.y + inf_t[0][1]] = 65 + tetr_ind;
	(*gameboard)[pos.x + inf_t[1][0]][pos.y + inf_t[1][1]] = 65 + tetr_ind;
	(*gameboard)[pos.x + inf_t[2][0]][pos.y + inf_t[2][1]] = 65 + tetr_ind;
	(*gameboard)[pos.x + inf_t[3][0]][pos.y + inf_t[3][1]] = 65 + tetr_ind;
}

int			solveit(char ***gameboard, int ***tetrisboard, t_cord n)
{
	t_cord	t;
	int		tetnum;

	tetnum = 0;
	while (tetnum < n.y && tetnum > -1)
	{
		t = is_safe(gameboard, tetrisboard[tetnum], n.x, tetnum);
		if (t.x != -99 && t.y != -99)
		{
			put_tet(gameboard, tetrisboard[tetnum], t, tetnum);
			tetnum++;
		}
		else
			tetnum--;
	}
	if (tetnum == n.y)
		return (1);
	return (0);
}
