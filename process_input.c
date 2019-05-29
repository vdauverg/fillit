/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:36:09 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/27 21:27:30 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino	*check_blocks(t_block *blocks, int fd)
{
	int			i;
	int			j;
	int			diff;
	int			connections;
	t_tetrimino	*tetrimino;

	connections = 0;
	i = 0;
	blocks->touching = ft_strnew(4);
	ft_bzero(blocks->touching, 4);
	tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino));
	while (i < 4)
	{
		j = 0;
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
	t_block	*blocks;

	num = 0;
	i = 0;
	x = 3;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			num++;
			(x > i % 4) ? x = i % 4 : 0;
		}
		i++;
	}
	if (i == 16 && num == 4)
	{
		blocks = (t_block *)malloc(sizeof(t_block) * 5);
		num = 0;
		i = 0;
		while (piece[i] && num < 4)
		{
			(!num) ? y = i / 4 : 0;
			if (piece[i] == '#')
			{
				blocks[num].x = i % 4 - x;
				blocks[num++].y = i / 4 - y;
			}
			i++;
		}
		return (check_blocks(blocks, fd));
	}
	return (NULL);
}

int			read_piece(int fd, t_tetrimino **tmp)
{
	int		i;
	int		len;
	char	*line;
	char	*piece;

	piece = "";
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*line) ? len = ft_strlen(line) : 0;
		if (*line && len == 4)
			piece = ft_strjoin(piece, line);
		else if (len == 4 && i == 4)
		{
			ft_strdel(&line);
			*tmp = check_piece(piece, fd);
			return (1);
		}
		else
			return (0);
		(line) ? ft_strdel(&line) : 0;
		i++;
	}
	return (2);
}

t_tetrimino	**read_input(char *input)
{
	int			fd;
	int			num;
	int			check;
	t_tetrimino	*tmp;
	t_tetrimino	**tetriminos;

	((fd = open(input, O_RDONLY)) <= 0) ? safe_exit(0) : 0;
	tetriminos = (t_tetrimino **)malloc(sizeof(t_tetrimino *) * 27);
	num = 0;
	tmp = NULL;
	while ((check = read_piece(fd, &tmp)) != 2)
	{
		if (check)
			tetriminos[num] = tmp;
		else
		{
			(tmp) ? free(tmp) : 0;
			while (--num >= 0)
				free(tetriminos[num]) ;
			free(tetriminos);
			safe_exit(fd);
		}
		tmp = NULL;
		num++;
	}
	close(fd);
	while (num < 26)
		tetriminos[num++] = NULL;
	return (tetriminos);
}
