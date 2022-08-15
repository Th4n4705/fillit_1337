/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masali <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 16:25:49 by masali            #+#    #+#             */
/*   Updated: 2019/05/20 15:15:57 by masali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>
# define BUFF_SIZE 32
# define BK_SLSHN_POS pos[0]
# define READ_VAL pos[1]
# define F_LINE_LEN pos[2]

typedef struct		s_save
{
	int				fd;
	char			*data;
	struct s_save	*next;
}					t_save;

typedef struct		s_v
{
	int				x;
	int				y;
}					t_cord;

typedef struct		s_safe
{
	int				boardsize;
	int				tetnum;
	int				ver;
	int				i;
}					t_safe;

int					get_tetris_lines(const int fd, char **line);
void				tetristoboard(int indice, int ****tetriboard
						, char tetris[4][4]);
void				align(int ***infotetris);
void				infopoint(char tetris[4][4], int ***infotetris);
int					tetrishredder(char *all_the_file
						, int ****tetriboard, int numoftet);
int					gameboardsize(int numtetris);
int					fourchars(char *s);
int					count_tetrominos(char *s);
int					between_tetrominos(char *s);
int					valstring(char *s);
int					fourlines(char fourln[4][4]);
int					valid_tab_caracter(char tetris[4][4]);
int					valid_shape(char tetris[4][4]);
int					all_valid(char tetris[4][4]);
int					reader(char **s, char *filename);
int					safe_helper(t_cord s, char **gameboard
						, int **inf_t, int boardsize);
t_cord				is_safe(char ***gameboard, int **infotetris
						, int boardsize, int tetnum);
char				**mallocgameboard(int x);
int					***malloctetrisboard(int z);
int					putinboard(char ***gameboard, int **inf_t
						, int tetr_ind, int boardsize);
int					solveit(char ***gameboard, int ***tetrisboard, t_cord n);
void				reset(char ***gameboard, int **inf_t, int x, int y);
void				put_tet(char ***gameboard, int **inf_t, t_cord pos
						, int tetr_ind);
void				free_gameboard(char ***gameboard, int x);
void				freetetrisboard(int ****tetrisboard, int numboftet);
#endif
