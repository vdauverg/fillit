/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/28 21:38:09 by vdauverg         ###   ########.fr       */
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
					int max_map_value, int ti);
char			make_map(char **map, int map_size);
char			*place_block(char **map, int ti, unsigned char **coordinates);

//	Main
void			safe_exit(int fd);
#endif
