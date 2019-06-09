/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/08 22:48:06 by vdauverg         ###   ########.fr       */
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
		points.y++;
	if (x > tmp_x)
		points.x++;
	if (x < tmp_x)
		points.x--;
	if (x < tmp_x && x < tmp_x - 1)
		points.x--;
	return (points);
}

char	**first_block(char **map, t_pos *points)
{
	int	x;
	int	y;

	x = points->x;
	y = points->y;
	while (map[y] && map[y][x] != '.')
	{
		x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
	}
	points->x = x;
	points->y = y;
	return (map);
}
