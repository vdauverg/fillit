/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:12:23 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/29 20:50:54 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**special_case(char **map, t_tetrimino **tetriminos, int i, int ti, int map_x, int map_y)
{
	//int x;
	//int y;
	int tmp_x;
	int tmp_y;

	tmp_x = tetriminos[ti]->blocks[i - 1].x;
	tmp_y = tetriminos[ti]->blocks[i - 1].y;
	//x = tetriminos[ti]->blocks[i].x;
	//y = tetriminos[ti]->blocks[i].x;
	while (tmp_x > 0)
	{
		map_x++;
		tmp_x--;
	}
	return (map[map_y][map_x]);
}
