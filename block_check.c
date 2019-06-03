/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/03 07:19:24 by vdauverg         ###   ########.fr       */
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

char	**first_block(char **map, t_tetrimino *tetriminos, \
			t_pos *points, int *prev_start)
{
	int	x;
	int	y;

	x = points->map_x;
	y = points->map_y;
	while (map[y] && map[y][x] != '.' && \
		!(map[y + 1][x] != '.' || map[y][x + 1] != '.'))
	{
		ft_putendl("hello");
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
	return (special_case(map, tetriminos, points));
}

char	**special_case(char **map, t_tetrimino *tetriminos, t_pos *points)
{
	int	tmp_x;

	tmp_x = tetriminos->blocks[0].x;
	while (tmp_x > 0)
	{
		points->map_x++;
		tmp_x--;
	}
	return (map);
}
