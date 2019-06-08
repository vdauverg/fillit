/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/07 21:49:34 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_pos	map_increment(t_tetrimino *tetriminos, t_pos points, int i)
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;


	tmp_x = tetriminos->blocks[i - 1].x;
	tmp_y = tetriminos->blocks[i - 1].y;
	x = tetriminos->blocks[i].x;
	y = tetriminos->blocks[i].y;
	if (y > tmp_y)
		points.map_y++;
	if (x > tmp_x)
		points.map_x++;
	if (x < tmp_x)
		points.map_x--;
	if (x < tmp_x && x < tmp_x - 1)
		points.map_x--;
	return (points);
}

char	**first_block(char **map, t_pos *points, int *prev_start)
{
	int	x;
	int	y;

	x = points->map_x;
	y = points->map_y;
	while (map[y] && map[y][x] != '.')
	{
		x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
	}
	points->map_x = x;
	points->map_y = y;
	prev_start[0] = x;
	prev_start[1] = y;
	return (map);
}
