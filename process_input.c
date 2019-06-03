/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:36:09 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/02 18:03:54 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			find_adjacent_blocks(t_tetrimino *tetrimino, t_block *blocks, int i)
{
	int	j;
	int	diff;
	int	connections;

	j = 0;
	connections = 0;
	while (j < 4)
	{
		(i == j) ? j++ : 0;
		diff = blocks[i].y - blocks[j].y;
		if (blocks[i].x == blocks[j].x && (diff == 1 || diff == -1))
		{
			tetrimino->height++;
			connections++;
		}
		diff = blocks[i].x - blocks[j].x;
		if (blocks[i].y == blocks[j].y && (diff == 1 || diff == -1))
		{
			tetrimino->width++;
			connections++;
		}
		j++;
	}
	return (connections);
}

t_tetrimino	*check_blocks(t_block *blocks, int fd)
{
	int			i;
	int			connections;
	t_tetrimino *tetrimino;

	connections = 0;
	i = 0;
	tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	while (i < 4)
	{
		connections += find_adjacent_blocks(tetrimino, blocks, i);
		i++;
	}
	if (connections < 6)
	{
		tetrimino = NULL;
		free(blocks);
		free(tetrimino);
		safe_exit(fd);
	}
	tetrimino->blocks = blocks;
	tetrimino->height /= 2;
	tetrimino->width /= 2;
	return (tetrimino);
}

t_tetrimino	*check_piece(char *piece, int fd)
{
	int		i;
	int		y;
	int		x;
	int		num;
	t_block *blocks;

	num = 0;
	i = -1;
	x = 3;
	while (piece[++i])
		(piece[i] == '#' && ++num && x > i % 4) ? x = i % 4 : 0;
	if (!(i == 16 && num == 4))
		return (NULL);
	blocks = (t_block *)malloc(sizeof(t_block) * 5);
	num = 0;
	i = -1;
	while (piece[++i] && num < 4)
	{
		(!num) ? y = i / 4 : 0;
		if (piece[i] == '#')
			blocks[num].x = i % 4 - x;
		if (piece[i] == '#')
			blocks[num++].y = i / 4 - y;
	}
	return (check_blocks(blocks, fd));
}
