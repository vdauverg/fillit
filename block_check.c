/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/29 20:50:59 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**map_increment(char **map, t_tetrimino **tetriminos, int i, int ti, int map_x, int map_y)
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;

	tmp_x = tetriminos[ti]->blocks[i - 1].x;
	tmp_y = tetriminos[ti]->blocks[i - 1].y;
	x = tetriminos[ti]->blocks[i].x;
	y = tetriminos[ti]->blocks[i].y;
	if (y > tmp_y)
		map_y++;
	if (x > tmp_x)
		map_x++;
	if (map_x == '\0' || map_y > max_y == '\0')
		return (1);
	if (x < tmp_x)
		map_x--;
	return (map[map_y][map_x]);
}

char		**first_block(char **map, int map_x, int map_y)
{
	while (map[map_y][map_x] != '.')
	{
		map_x++;
		if (map_x == '\0')
		{
			map_x = 0;
			map_y++;
		}
	}
	return (special_case(map, tetriminos, i, ti, map_x, map_y));
}
