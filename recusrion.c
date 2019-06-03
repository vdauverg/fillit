/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recusrion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:47:40 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/02 23:28:55 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**recursion(char **map, t_tetrimino **tetriminos, int rec_i, int ti, int map_size)
{
	char	t_letter;
	char	**new_map;
	int		no;

	t_letter = 'a';
	t_letter = t_letter + ti;
	new_map = NULL;
	no = 0;
	while (tetriminos[ti] != '\0')
	{
		no = check_map(map, tetriminos, map_size, ti);
		if (no == 2)
		{
			ti--;
			rec_i++;
			if (rec_i > 1000)
			{
				rec_i = 0;
				new_map = map_increase(map, map_size);
			}
				recursion(map, tetriminos, rec_i, ti, map_size);
		}
 		else if (no == 1)
		{
			new_map = map_increase(map, map_size);
			rec_i = 0;
			recursion(map, tetriminos, rec_i, ti, map_size);
		}
		ti++;
	}
	return (map);
}

/*char		**remove_letter(char **map, char t_letter)
{
	int i;
	int j;

	while (map[j])
	{
		if (map[j][i] == t_letter - 1 )
			map[j][i] = '.';
		else
		{
			i++;
			if (!map[j][i])
			{
				i = 0;
				j++;
			}
		}
	}
	return (map);
}*/

char		**map_increase(char **map, int map_size)
{
	return (map);
}
