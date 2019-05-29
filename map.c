/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:49:57 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/28 16:08:01 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char			make_map(char **map, int map_size)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (map[y][x] != '\0')
	{
		if (x == '\0')
		{
			x = 0;
			y++;
		}
		else
		{
			map[y][x] = '.';
			x++;
		}
	}
	map_size++;
	return (map_size);
}

char			*place_block(char **map, int ti, unsigned char **coordinates)
{
	int		i;
	int		point;
	char	t_letter;

	i = 0;
	point = 0;
	t_letter = 'a';
	t_letter = t_letter + ti;
	while (coordinates[i][point] != '\0')
	{
		map[coordinates[i][point]][coordinates[i][point + 1]] = t_letter;
		i++;
	}
	return (*map);
}
