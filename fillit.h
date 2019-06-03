/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/03 08:09:23 by vdauverg         ###   ########.fr       */
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
}				t_tetrimino;

typedef struct	s_pos
{
	int map_x;
	int map_y;
	int i;
}				t_pos;

//	Process Input
void			free_exit(t_tetrimino *tmp, t_tetrimino **tetriminos, \
				int num, int fd);
int				find_adjacent_blocks(t_tetrimino *tetrimino, \
				t_block *blocks, int i);
int				read_piece(int fd, t_tetrimino **tmp);
t_tetrimino		*check_blocks(t_block *blocks, int fd);
t_tetrimino		*check_piece(char *piece, int fd);
t_tetrimino		**read_input(char *input);

//	Checking Map and Tetrimino Placement
int				*check_map(char **map, t_tetrimino *tetriminos, \
					int *prev_start);
char			**place_block(char **map, t_tetrimino *tetriminos, \
					int ti, int *prev_start);
t_pos			map_increment(t_tetrimino *tetriminos, t_pos points, int i);
char			**first_block(char **map, t_tetrimino *tetriminos, \
					t_pos *points, int *prev_start);
char			**special_case(char **map, t_tetrimino *tetriminos, \
					t_pos *points);
int				**transfer(char **map, t_pos *points, int **coordinates, int i);
int				**coord_init(int **coordinates);

//	Main
void			ft_putstrx2(char **map);
char			**map_init(int num);
void			safe_exit(int fd);
// char			**recursion(char **map, t_tetrimino **tetriminos, int rec_i, \
// 					int ti, int map_size);
char			**recursion(char **map, t_tetrimino **tetriminos, int ti, int *prev_start);
char			**map_increase(char **map, int map_size);
#endif
