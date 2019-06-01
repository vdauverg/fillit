/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/01 04:36:28 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		map_increment(t_tetrimino *tetriminos, t_pos points)
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;

	tmp_x = tetriminos->blocks[points.i - 1].x;
	tmp_y = tetriminos->blocks[points.i - 1].y;
	x = tetriminos->blocks[points.i].x;
	y = tetriminos->blocks[points.i].y;
	if (y > tmp_y)
		points.map_y++;
	if (x > tmp_x)
		points.map_x++;
	if (x < tmp_x)
		points.map_x--;
}

char	**first_block(char **map, t_tetrimino **tetriminos, t_pos points, int ti)
{
	while (map[points.map_y] && map[points.map_y][points.map_x] != '.')
	{
		points.map_x++;
		if (!map[points.map_y][points.map_x])
		{
			points.map_x = 0;
			points.map_y++;
		}
	}
	return (special_case(map, tetriminos[ti], points));
}

char	**special_case(char **map, t_tetrimino *tetriminos, t_pos points)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = tetriminos->blocks[0].x;
	tmp_y = tetriminos->blocks[0].y;
	while (tmp_x > 0)
	{
		points.map_x++;
		tmp_x--;
	}
	return (map);
}
