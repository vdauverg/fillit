/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 04:30:11 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/24 01:10:36 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_map(char **map, t_tetrimino **tetriminos, int max_map_value, int ti)
{
	unsigned char **coordinates;
	int point;
	int x;
	int y;
	int tmp_x;
	int tmp_y;
	int map_x;
	int map_y;
	int i;

	i = 0;
	map_x = 0;
	map_y = 0;
	point = 0;
	coordinates = NULL;
	x = tetriminos[ti] -> blocks[i].x;
	y = tetriminos[ti] -> blocks[i].y;
	while (i != 4)
	{
		if (map[max_map_value][max_map_value] == '\0')
		{
			if (map[map_y][map_x] != '.')
				map_x++;
			else if (map[map_y][map_x] == '\0')
			{
				map_x = 0;
				map_y++;
			}
			else if (map[map_y][map_x] == '.')
			{
				i++;
				tmp_x = x;
				tmp_y = y;
				x = tetriminos[ti] -> blocks[i].x;
				y = tetriminos[ti] -> blocks[i].y;
				if (y > tmp_y)
					map_y++;
				while (x != tmp_x)
				{
					if (x > tmp_x)
						map_x++;
					if (x == '\0')
						return (1);
					else
						map_x--;
				}
				coordinates[i][point] = map_x;
				point++;
				coordinates[i][point] = map_y;
				point++;
			}
		//Needs an if statement to be in. or is it fine as i already have 
		//a return statement to put errors
		//Rerun check recursively with an incrementing parameter?
			i++;
			map_x++;
		}
	}
	place_block(map, ti, coordinates);
	return (0);
}
