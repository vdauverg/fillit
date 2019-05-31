/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/31 02:18:36 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_map(char **map, t_tetrimino **tetriminos, int mmv, int ti)
{
	unsigned char	**coordinates;
	int				point;
	int				i;
	t_pos			points;

	i = 1;
	point = 0;
	points.map_x = 0;
	points.map_y = 0;
	points.i = 0;
	coordinates = NULL;
	first_block(map, tetriminos, points, ti);
	while ((points.map_x < mmv && points.map_y < mmv) && i < 4)
	{
		if (map[points.map_y][points.map_x] == '\0' && points.map_y < mmv)
		{
			points.map_x = 0;
			points.map_y++;
		}
		else
			return (1);
		map_increment(map, tetriminos[ti], points);
		//make the points equal something
		//Move up the cooridnates point part
		i++;
		if (map[points.map_y][points.map_x] == '.')
		{
			coordinates[i][point] = points.map_x;
			point++;
			coordinates[i][point] = points.map_y;
			point++;
			points.map_x++;
		}
		else
			return (1);
	}
	place_block(map, ti, coordinates);
	return (0);
}
