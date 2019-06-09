/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:17:27 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/08 19:55:19 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**recursion(char **map, t_tetrimino **tetriminos, int ti, t_pos points)
{
	int		**co;
	t_pos	*tmp_points;

	tmp_points = (t_pos *)malloc(sizeof(t_pos));
	co = NULL;
	coord_init(co);
	points = check_map(map, tetriminos[ti], co, points);
	while (points.ret == 0)
	{
		points.x++;
		points = check_map(map, tetriminos[ti], co, points);
	}
	if (points.ret == -1)
	{
		map_del(map);
		return (map);
	}
	*tmp_points.x = points.x;
	*tmp_points.y = points.y;
	*tmp_points.ret = points.ret;
	while ((map = recursion(map, teriminos, ti, tmp_points)))
	{
		points.x++;
	}
}

char	**place_block(char **map, int ti, int **coordinates)
{
	char	t_letter;
	int		i;

	t_letter = 'A';
	t_letter = t_letter + ti;
	i = 0;
	while (i < 4)
	{
		map[coordinates[i][1]][coordinates[i][0]] = t_letter;
		i++;
	}
	return (map);
}

void		map_del(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
