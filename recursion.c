/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:47:40 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/03 09:12:25 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char		**recursion(char **map, t_tetrimino **tetriminos, int rec_i, int ti, int map_size)
// {
// 	char	t_letter;
// 	char	**new_map;
// 	int		no;

// 	t_letter = 'a';
// 	t_letter = t_letter + ti;
// 	new_map = NULL;
// 	no = 0;
// 	while (tetriminos[ti] != '\0')
// 	{
// 		no = check_map(map, tetriminos, map_size, ti);
// 		if (no == 2)
// 		{
// 			ti--;
// 			rec_i++;
// 			if (rec_i > 1000)
// 			{
// 				rec_i = 0;
// 				new_map = map_increase(map, map_size);
// 			}
// 				recursion(map, tetriminos, rec_i, ti, map_size);
// 		}
//  		else if (no == 1)
// 		{
// 			new_map = map_increase(map, map_size);
// 			rec_i = 0;
// 			recursion(map, tetriminos, rec_i, ti, map_size);
// 		}
// 		ti++;
// 	}
// 	return (map);
// }

char	**recursion(char **map, t_tetrimino **tetriminos, int ti, int *prev_start)
{
	char	**tmp_map;
	int		i;
	int		size;
	
	i = -1;
	size = ft_strlen(map[0]);
	tmp_map = (char **)malloc(sizeof(char *) * (size + 1));
	tmp_map[size] = NULL;
	while (tmp_map[++i])
		tmp_map[i] = ft_strdup(map[i]);
	i = 0;
	while (i == 0 || prev_start[2] == 0)
	{
		prev_start[0]++;
		prev_start = check_map(tmp_map, tetriminos[ti], prev_start);
		i++;
	}
	if (prev_start[2] != 0)
	{
		tmp_map = recursion(tmp_map, tetriminos, ti++, prev_start);
		map = tmp_map;
		map = place_block(tmp_map, tetriminos[ti], ti, prev_start);
	}
	else
		map = map_increase(map, size);
	i = 0;
	while (tmp_map[i])
			free(tmp_map[i++]);
		free(tmp_map);
		tmp_map = NULL;
	return(map);
}

char		**map_increase(char **map, int map_size)
{
	int j;
	int i;
	char **new_map;

	j = 0;
	new_map = (char **)malloc(sizeof(char *) * (map_size + 1));
	i = ft_strlen(new_map[j]);
	new_map[map_size] = NULL;
	while (new_map[j])
	{
		new_map[j] = (char *)malloc(sizeof(char) * (map_size + 1));
		new_map[j] = ft_strcpy(new_map[j], map[j]);
		new_map[j][i] = '.';
		j++;
		if (j == i)
		{
			i = 0;
			while (new_map[j][i] != '\0')
			{
				new_map[j][i] = '.';
				i++;
			}
			break ;
		}
	}
	return (new_map);
}
