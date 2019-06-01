/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/01 04:32:45 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_map(char **map, t_tetrimino **tetriminos, int mmv, int ti)
{
	unsigned char	**coordinates;
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
			return (-1);
	}
	map = place_block(map, ti, coordinates, points);
	ft_putstrx2(map);
	return (0);
}

unsigned char	**transfer(char **map, t_pos points,
		unsigned char **coordinates)
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
