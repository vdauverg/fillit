/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:36:09 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/23 14:31:42 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		safe_exit()
{
	write(1, "usage: ./fillit source_file\n", 28);
	exit(0);
}

t_tetrimino	*check_blocks(t_block *blocks) // Check that blocks within a tetrimino connect together
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
		safe_exit();
	}
	tetrimino->blocks = blocks;
	tetrimino->height /= 2;
	tetrimino->width /= 2;
	return (tetrimino);
}

t_tetrimino	*check_piece(char *piece) // Check that four blocks are in the tetrimino
{
	int		i;
	int		y;
	int		x;
	int		num;
	t_block	*blocks;

	num = 0;
	i = 0;
	x = 3;

	// Count blocks and check for left-most piece
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			num++;
			(x > i % 4) ? x = i % 4 : 0;
		}
		i++;
	}

	// If 4 blocks, malloc array of t_blocks and set x & y values
	if (i == 16 && num == 4)
	{
		blocks = (t_block *)malloc(sizeof(t_block) * 5);
		num = 0;
		i = 0;
		while (piece[i] && num < 4)
		{
			(!num) ? y = i / 4 : 0; // Check for top-most piece
			if (piece[i] == '#')
			{
				blocks[num].x = i % 4 - x; // Set x to left-most position possible
				blocks[num++].y = i / 4 - y; // Set y to up-most position possible
			}
			i++;
		}
		return (check_blocks(blocks)); // Check the blocks then return the tetrimino
	}
	return (NULL); // Otherwise return nothing
}

t_tetrimino	**read_input(char *input)
{
	int			fd;
	int			i;
	int			num;
	char		*line;
	char		*piece;
	t_tetrimino	**tetriminos;

	fd = open(input, O_RDONLY);
	tetriminos = (t_tetrimino **)malloc(sizeof(t_tetrimino *) * 27);
	tetriminos[26] = NULL;
	piece = "";

	i = 0;
	num = 0;
	while (get_next_line(fd, &line) > 0) // Read line by line until EOF or error
	{
		// If *line and *line is 4 long add line to piece
		if (*line && ft_strlen(line) == 4)
				piece = ft_strjoin(piece, line);

		// Else if 4 lines read and piece is valid (function)
		else if (i == 4 && (tetriminos[num] = check_piece(piece))) 
		{
			// Increment piece index, reset i and clear piece
			num++;
			i = -1;
			ft_strclr(piece);
		}

		// Else (not 4 lines read / tetrimino not valid)
		else
		{
			// Delete line, free tetriminos and return NULL
			(line) ? ft_strdel(&line) : 0;
			while (num >= 0)
				(tetriminos[num]) ? free(tetriminos[num--]) : 0;
			free(tetriminos);
			close(fd);
			safe_exit();
		}

		// Free line, increment line number of tetrimino
		(line) ? ft_strdel(&line) : 0;
		i++;
	}

	close(fd);

	// Set remaining tetriminos to NULL
	while (num < 26)
		tetriminos[num++] = NULL;

	return (tetriminos);
}
