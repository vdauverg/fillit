/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/28 22:14:48 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_map(char **map, t_tetrimino **tetriminos, int max_map_value, int ti)
{
	unsigned char	**coordinates;
	int				point;
	int				map_x;
	int				map_y;
	int				i;

	i = 0;
	map_x = 0;
	map_y = 0;
	point = 0;
	coordinates = NULL;
	first_block(map, map_x, map_y);
	i++;
	while (map[max_map_value][max_map_value] == '\0' && i < 4)
	{
		if (map[map_y][map_x] == '\0' && map_y < max_map_value)
		{
			map_x = 0;
			map_y++;
		}
		else
			return (1);
		map_increment(map, tetriminos, i, ti, map_x, map_y);
		i++;
		if (map[map_y][map_x] == '.')
		{
			coordinates[i][point] = map_x;
			point++;
			coordinates[i][point] = map_y;
			point++;
			map_x++;
		}
		else
			return (1);
	}
	place_block(map, ti, coordinates);
	return (0);
}
