/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/09 04:28:04 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "libft/get_next_line.h"

typedef struct	s_block
{
	int		x;
	int		y;
}				t_block;

typedef struct	s_tetrimino
{
	t_block	*blocks;
	int		width;
	int		height;
	int		placed;
}				t_tetrimino;

typedef struct	s_pos
{
	int x;
	int y;
	int	rec;
}				t_pos;

void			free_exit(t_tetrimino *tmp, t_tetrimino **tetriminos, \
				int num, int fd);
int				find_adjacent_blocks(t_tetrimino *tetrimino, \
				t_block *blocks, int i);
int				read_piece(int fd, t_tetrimino **tmp);
t_tetrimino		*check_blocks(t_block *blocks, int fd);
t_tetrimino		*check_piece(char *piece, int fd);
t_tetrimino		**read_input(char *input);
int				check_map(char **map, t_tetrimino *tetriminos, \
					int ti, t_pos *po);
char			**place_tet(char **map, int ti, \
					int **coordinates);
t_pos			map_increment(t_tetrimino *tetriminos, t_pos points, int i);
char			**first_block(char **map, t_pos *points);
char			**special_case(char **map, t_tetrimino *tetriminos, \
					t_pos *points);
int				**t(char **map, t_pos *points, int **coordinates, int i);
int				**coord_init(int **coordinates);
void			map_del(char **map);
void			ft_putstrx2(char **map);
char			**map_init(t_tetrimino **tetriminos);
void			safe_exit(int fd);
char			**recursion(char **map, t_tetrimino **tetriminos, int ti, t_pos points);
int				recurse(char ***map, t_tetrimino **tetriminos, int ti, t_pos points);
int				try_place(char ***map, t_tetrimino **tetriminos, int ti, t_pos points);
// char			**recursion(char **map, t_tetrimino **tetriminos, int ti, \
		// int *prev_start);
char			**map_increase(char **map);
char			**map_dup(char **map);
#endif
