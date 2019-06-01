/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/01 07:48:23 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int				check_map(char **map, t_tetrimino **tetriminos, int mmv, int ti)
{
	int				**coordinates;
	int				i;
	t_pos			points;

	i = 1;
	points.map_x = 0;
	points.map_y = 0;
	points.i = 0;
	coordinates = NULL;
	first_block(map, tetriminos, points, ti);
	while (points.i < 4)
	{
	printf("Printf");
		if (map[points.map_y][points.map_x] == '\0' && points.map_y < mmv)
		{
			points.map_x = 0;
			points.map_y++;
		}
		else
			return (-1);
		map_increment(tetriminos[ti], points);
		//make the points equal something
		//Move up the cooridnates point part
		if (!transfer(map, points, coordinates))
			//not saving data
			return (-1);
		points.map_x++;
	}
	map = place_block(map, ti, coordinates, points);
	ft_putstrx2(map);
	return (0);
}

int		**transfer(char **map, t_pos points, int **coordinates)
{
	if (map[points.map_y][points.map_x] == '.')
	{
		coordinates[points.i][0] = points.map_x;
		coordinates[points.i][1] = points.map_y;
	}
	else
		ft_strdel((char **)coordinates);
		//coordinates = NULL;
	points.i++;
	return (coordinates);
}

int		**coord_init(int **coordinates)
{
	int		i;

	coordinates = (int **)malloc(sizeof(int *) * (5));
	coordinates[4] = NULL;
	i = 0;
	while (i < 3)
	{
		coordinates[i] = (int *)malloc(sizeof(int) * (3));
		coordinates[i][2] = '\0';
		i++;
	}
	return (coordinates);
}
