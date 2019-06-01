/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/29 15:41:40 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_map(char **map, t_tetrimino **tetriminos, int mmv, int ti)
{
	unsigned char	**coordinates;
	int				point;
	int				map_x;
	int				map_y;
	int				i;

	i = 1;
	map_x = 0;
	map_y = 0;
	point = 0;
	coordinates = NULL;
	first_block(map, map_x, map_y);
	while ((map_x < mmv || map_y < mmv) && i < 4)
	{
		if (map[map_y][map_x] == '\0' && map_y < mmv)
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
