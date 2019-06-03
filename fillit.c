/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/03 07:24:35 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	safe_exit(int fd)
{
	(fd) ? close(fd) : 0;
	ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

int		square_root(int num)
{
	int	i;

	i = 1;
	if (num <= 1)
		return (num);
	while ((i * i) <= num)
		i++;
	return (i);
}

char	**map_init(int num)
{
	int		i;
	int		j;
	char	**map;

	num = square_root(num * 4);
	map = (char **)malloc(sizeof(char *) * (num + 1));
	map[num] = NULL;
	i = 0;
	while (i < num)
	{
		map[i] = (char *)malloc(sizeof(char) * (num + 1));
		map[i][num] = 0;
		j = 0;
		while (j < num)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_putstrx2(char **map)
{
	int j;

	j = 0;
	while (map[j])
	{
		ft_putendl(map[j]);
		j++;
	}
}

char	**place_block(char **map, t_tetrimino *tetriminos, int ti, int *prev_start)
{
	char	t_letter;
	int		i;
	int		x;
	int		y;

	t_letter = 'A';
	t_letter = t_letter + ti;
	i = 0;
	ft_putnbr(prev_start[0]);
	ft_putchar(' ');
	ft_putnbr(prev_start[1]);
	ft_putchar('\n');
	while (i < 4)
	{
		x = tetriminos->blocks[i].x + prev_start[0];
		y = tetriminos->blocks[i].y + prev_start[1];
		map[y][x] = t_letter;
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	int			ti;
	int			map_size;
	int			*prev_start;
	char		**map;
	int			i;
	t_tetrimino **tetriminos;

	if (argc == 2)
	{
		i = 0;
		if (!(tetriminos = read_input(argv[1])))
			safe_exit(0);
		map_size = 0;
		while (tetriminos[map_size])
			map_size++;
		map = map_init(map_size);
		prev_start = (int *)malloc(sizeof(int) * 3);
		prev_start[0] = 0;
		prev_start[1] = 0;
		prev_start[2] = 1;
		ti = 0;
		prev_start = check_map(map, tetriminos[ti], map_size, prev_start);
		if (prev_start[2] != 0)
		{
			map = place_block(map, tetriminos[ti], ti, prev_start);
			ti++;
			while ((i == 0 || prev_start[2] == 0) && prev_start[0] < 10)
			{
				prev_start[0]++;
				prev_start = check_map(map, tetriminos[ti], map_size, prev_start);
				i++;
			}
			if (prev_start[2] != 0)
			{
				map = place_block(map, tetriminos[ti], ti, prev_start);
				ti++;
				while ((i == 0 || prev_start[2] == 0) && prev_start[0] < 10)
				{
					prev_start[0]++;
					prev_start = check_map(map, tetriminos[ti], map_size, prev_start);
					i++;
				}
				if (prev_start[2] != 0)
				{
					map = place_block(map, tetriminos[ti], ti, prev_start);
				}
			}
		}
		ft_putstrx2(map);
	}
	else
		safe_exit(0);
	return (0);
}
