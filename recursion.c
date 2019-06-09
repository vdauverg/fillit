/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:47:40 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/08 05:25:36 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**recursion(char **map, t_tetrimino **tetriminos, int rec_num, int *prev_start)
{
	char	**tmp_map;
	int		size;
	int		i;
	int		start;
	int		placed;
	int		ti;

	rec_num++;
	start = 0;
	size = ft_strlen(map[0]);
	tmp_map = (char **)malloc(sizeof(char *) * (size + 1));
	tmp_map[size] = NULL;
	i = 0;
	placed = 0;
	ti = 0;
	while (i < size)
	{
		tmp_map[i] = ft_strdup(map[i]);
		i++;
	}
	while (tetriminos[ti])
	{
		prev_start[0] = start % size;
		prev_start[1] = start / size;
		if (tetriminos[ti]->placed == 0)
		{
			i = 0;
			while (i == 0 || prev_start[2] == 0)
			{
				prev_start = check_map(tmp_map, tetriminos[ti], ti, prev_start);
				prev_start[0]++;
				i++;
				start++;
			}
			if (prev_start[2] == 1)
			{
				tetriminos[ti]->placed = 1;
				tmp_map = recursion(tmp_map, tetriminos, rec_num, prev_start);
				if (prev_start[2] == -1)
				{
					i = -1;
					while (tmp_map[++i])
						ft_strcpy(tmp_map[i], map[i]);
					tetriminos[ti]->placed = 0;
					ti--;
				}
				else
					placed++;
			}
			else
				start = 0;
		}
		else
			placed++;
		ti++;
	}
	if (rec_num == 0 && placed == 0)
	{
		ft_putendl("INCREASING MAP!!!");
		map = map_increase(map, size);
		map = recursion(map, tetriminos, -1, prev_start);
	}
	else if (prev_start[2] == 1)
	{
		i = 0;
		while (map[i])
		{
			ft_strcpy(map[i], tmp_map[i]);
			i++;
		}
	}
	i = 0;
	map_del(tmp_map);
	return (map);
}

char		**map_increase(char **map, int map_size)
{
	int		j;
	int		i;
	char	**new_map;

	j = 0;
	i = map_size;
	new_map = (char **)malloc(sizeof(char *) * (++map_size + 1));
	new_map[map_size] = NULL;
	while (j < i)
	{
		new_map[j] = (char *)malloc(sizeof(char) * (map_size + 1));
		new_map[j][map_size] = '\0';
		new_map[j] = ft_strcpy(new_map[j], map[j]);
		new_map[j][i] = '.';
		j++;
		if (j == i)
		{
			new_map[j] = (char *)malloc(sizeof(char) * (map_size + 1));
			i = 0;
			while (i < map_size)
			{
				new_map[j][i] = '.';
				i++;
			}
			new_map[j][i] = '\0';
			break ;
		}
	}
	map_del(map);
	return (new_map);
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
