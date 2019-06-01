/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/01 07:39:38 by vdauverg         ###   ########.fr       */
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
	char	*touching;
}				t_block;

typedef struct	s_tetrimino
{
	t_block	*blocks;
	int		placed;
	int		width;
	int		height;
}				t_tetrimino;

typedef struct s_pos
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
int				check_map(char **map, t_tetrimino **tetriminos, \
					int mmv, int ti);
int				**place_block(char **map, int ti, int **coordinates, t_pos points);
void			map_increment(t_tetrimino *tetriminos, t_pos points);
char			**first_block(char **map, t_tetrimino **tetriminos, t_pos points, int ti);
char			**special_case(char **map, t_tetrimino *tetriminos, t_pos points);
int				**transfer(char **map, t_pos points, int **coordinates);
void			ft_putstrx2(char **map);
//	Main
void			safe_exit(int fd);
#endif
