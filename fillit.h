/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/27 21:17:00 by vdauverg         ###   ########.fr       */
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
int			read_piece(int fd, t_tetrimino **tmp);
t_tetrimino	*check_blocks(t_block *blocks, int fd);
t_tetrimino	*check_piece(char *piece, int fd);
t_tetrimino	**read_input(char *input);

//	Main
void		safe_exit(int fd);
# endif
