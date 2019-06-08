/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/07 16:58:15 by vdauverg         ###   ########.fr       */
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

char	**map_init(t_tetrimino **tetriminos)
{
	int		i;
	int		j;
	int		num;
	char	**map;

	num = 0;
	while (tetriminos[num])
		num++;
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

char	**place_block(char **map, int ti, int **coordinates)
{
	char	t_letter;
	int		i;

	t_letter = 'A';
	t_letter = t_letter + ti;
	i = 0;
	while (i < 4)
	{
		map[coordinates[i][1]][coordinates[i][0]] = t_letter;
		i++;
	}
	return (map);
}

int		main(int argc, char **argv)
{
	int			*prev_start;
	char		**map;
	t_tetrimino **tetriminos;

	if (argc == 2)
	{
		if (!(tetriminos = read_input(argv[1])))
			safe_exit(0);
		map = map_init(tetriminos);
		prev_start = (int *)malloc(sizeof(int) * 3);
		prev_start[0] = 0;
		prev_start[1] = 0;
		prev_start[2] = 1;
		map = recursion(map, tetriminos, -1, prev_start);
		ft_putstrx2(map);
	}
	else
		safe_exit(0);
	return (0);
}
