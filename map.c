/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:49:57 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/01 03:44:22 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
		map[coordinates[i][point + 1]][coordinates[i][point]] = t_letter;
		i++;
	}
	printf(" Is ");
	return (*map);
}
