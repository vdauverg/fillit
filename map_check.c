/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/08 00:23:54 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	*check_map(char **m, t_tetrimino *tetriminos, int ti, int *prev_start)
{
	int				**co;
	t_pos			po;
	int				i;

	po.x = prev_start[0];
	po.y = prev_start[1];
	co = NULL;
	co = coord_init(co);
	first_block(m, &po, prev_start);
	i = 0;
	while (i < 4)
	{
		if (!m[po.y] || (!m[po.y + 1] && !m[po.y][po.x]) || (!t(m, &po, co, i)))
		{
			(!m[po.y] || (!m[po.y + 1] && !m[po.y]
				[po.x])) ? prev_start[2] = -1 :
				(prev_start[2] = 0);
			return (prev_start);
		}
		i++;
		po = map_increment(tetriminos, po, i);
	}
	prev_start[2] = 1;
	m = place_block(m, ti, co);
	return (prev_start);
}

int	**t(char **map, t_pos *points, int **coordinates, int i)
{
	if (map[points->y] && map[points->y][points->x] == '.')
	{
		coordinates[i][0] = points->x;
		coordinates[i][1] = points->y;
	}
	else
	{
		i = 0;
		while (coordinates[i])
			free(coordinates[i++]);
		free(coordinates);
		coordinates = NULL;
	}
	return (coordinates);
}

int	**coord_init(int **coordinates)
{
	int		i;

	coordinates = (int **)malloc(sizeof(int *) * (5));
	coordinates[4] = NULL;
	i = 0;
	while (i < 4)
	{
		coordinates[i] = (int *)malloc(sizeof(int) * (3));
		coordinates[i][2] = '\0';
		i++;
	}
	return (coordinates);
}
