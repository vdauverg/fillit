/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/06/01 03:20:31 by vdauverg         ###   ########.fr       */
=======
/*   Updated: 2019/06/01 03:40:18 by hecampbe         ###   ########.fr       */
>>>>>>> 92c3c7968336b5631091dd9bcab0e4a5cf16f679
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	safe_exit(int fd)
{
	(fd) ? close(fd) : 0;
	ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

// char	**map_init(int num)
// {
// 	int		i;
// 	int		j;
// 	char	**map;

// 	num *= 2;
// 	map = (char **)malloc(sizeof(char *) * (num + 1));
// 	map[num] = NULL;
// 	i = 0;
// 	while (i < num)
// 	{
// 		map[i] = (char *)malloc(sizeof(char) * (num + 1));
// 		map[i][num] = 0;
// 		j = 0;
// 		while (j < num)
// 		{
// 			map[i][j] = '.';
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (map);
// }

char	**map_init(int num)
{
	int		i;
	int		j;
	char	**map;

	num = 4;
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
	int			ti;
	int			map_size;
	t_tetrimino **tetriminos;

	if (argc == 2)
	{
		tetriminos = read_input(argv[1]);
		map_size = 0;
		while (tetriminos[map_size])
			map_size++;
		ti = 0;
		check_map(map_init(map_size), tetriminos, map_size, ti);
	}
	else
		safe_exit(0);
	//ft_putstrx2(map);
	return (0);
}

void	ft_putstrx2(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[j])
	{
		ft_putstr(map[j]);
		j++;
	}
}
