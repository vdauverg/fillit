/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/29 20:50:57 by hecampbe         ###   ########.fr       */
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
char			*place_block(char **map, int ti, unsigned char **coordinates);
char			**map_increment(char **map, t_tetrimino **tetriminos, int i, int ti, int map_x, int map_y);
char			**first_block(char **map, int map_x, int map_y);
char			**special_case(char **map, t_tetrimino **tetriminos, int i, int ti, int map_x, map_y);

//	Main
void			safe_exit(int fd);
#endif
