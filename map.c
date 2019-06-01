/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:49:57 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/01 04:36:20 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**place_block(char **map, int ti, unsigned char **coordinates, t_pos points)
{
	char	t_letter;

	t_letter = 'a';
	t_letter = t_letter + ti;
	while (coordinates[points.i])
	{
		map[coordinates[points.i][1]][coordinates[points.i][0]] = t_letter;
		points.i++;
	}
	return (map);
}
