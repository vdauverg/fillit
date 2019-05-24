/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/24 02:43:51 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FILLIT_H
# define	FILLIT_H
# include	"libft/libft.h"
# include	"libft/get_next_line.h"

typedef struct	s_block
{
	int		x;
	int		y;
	char	*touching;
}				t_block;

typedef struct	s_tetrimino
{
	t_block			*blocks;
	int				placed;
	int				width;
	int				height;
}				t_tetrimino;

//	Process Input
t_tetrimino	*check_blocks(t_block *blocks);
t_tetrimino	*check_piece(char *piece);
t_tetrimino	**read_input(char *input);
void		safe_exit();
int			check_map(char **map, t_tetrimino **tetriminos, int max_map_value, int ti);
char		make_map(char **map, int map_size);
char		*place_block(char **map, int ti, unsigned char **coordinates);

# endif
