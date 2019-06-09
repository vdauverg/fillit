/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/08 22:49:25 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_map(char **m, t_tetrimino *tetriminos, int ti, t_pos *po)
{
	int	i;
	int	ret;
	int	**co;

	co = NULL;
	co = coord_init(co);
	first_block(m, po);
	i = 0;
	while (i < 4)
	{
		if ((!m[po->y] || (!m[po->y + 1] && !m[po->y][po->x])) || (!t(m, po, co, i)))
		{
			(!m[po->y] || (!m[po->y + 1] && !m[po->y][po->x])) ? ret = -1 : (ret = 0);
			return (ret);
		}
		i++;
		*po = map_increment(tetriminos, *po, i);
	}
	m = place_tet(m, ti, co);
	return (1);
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

char	**place_tet(char **map, int ti, int **coordinates)
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
