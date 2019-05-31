/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_case.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:12:23 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/31 02:22:31 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**special_case(char **map, t_tetrimino *tetriminos, t_pos points)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = tetriminos->blocks[0].x;
	tmp_y = tetriminos->blocks[0].y;
	while (tmp_x > 0)
	{
		points.map_x++;
		tmp_x--;
	}
	return (map);
}
