/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/07 21:49:49 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*check_map(char **map, t_tetrimino *tetriminos, int ti, int *prev_start)
{
	int				**coordinates;
	t_pos			points;
	int				i;

	points.map_x = prev_start[0];
	points.map_y = prev_start[1];
	coordinates = NULL;
	coordinates = coord_init(coordinates);
	first_block(map, &points, prev_start);
	i = 0;
	while (i < 4)
	{
		if (!map[points.map_y])
		{
			prev_start[2] = -1;
			return (prev_start);
		}
		else if (!map[points.map_y + 1] && !map[points.map_y][points.map_x])
		{
			prev_start[2] = -1;
			return (prev_start);
		}
		if (!transfer(map, &points, coordinates, i))
		{
			prev_start[2] = 0;
			return (prev_start);
		}
		i++;
		points = map_increment(tetriminos, points, i);
	}
	prev_start[2] = 1;
	map = place_block(map, ti, coordinates);
	return (prev_start);
}

int	**transfer(char **map, t_pos *points, int **coordinates, int i)
{
	if (map[points->map_y] && map[points->map_y][points->map_x] == '.')
	{
		coordinates[i][0] = points->map_x;
		coordinates[i][1] = points->map_y;
	}
	else
	{
		i = 0;
		while (coordinates[i])
			free(coordinates[i++]);
		free(coordinates);
		coordinates = NULL;
	}
	return (coordinates);
}

int	**coord_init(int **coordinates)
{
	int		i;

	coordinates = (int **)malloc(sizeof(int *) * (5));
	coordinates[4] = NULL;
	i = 0;
	while (i < 4)
	{
		coordinates[i] = (int *)malloc(sizeof(int) * (3));
		coordinates[i][2] = '\0';
		i++;
	}
	return (coordinates);
}
