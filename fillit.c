/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/29 14:04:12 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	safe_exit(int fd)
{
	(fd) ? close(fd) : 0;
	ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

char	**map_init(t_tetrimino **tetriminos)
{
	int		i;
	int		j;
	int		num;
	char	**map;

	i = 0;
	num = 0;
	while (tetriminos[i++])
		num++;
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

int		main(int argc, char **argv)
{
	int			map_size;
	int			ti;
	t_tetrimino **tetriminos;

	if (argc == 2)
	{
		tetriminos = read_input(argv[1]);
		map_size = 4;
		ti = 0;
		check_map(map_init(tetriminos), tetriminos, map_size, ti);
	}
	else
		safe_exit(0);
	return (0);
}
