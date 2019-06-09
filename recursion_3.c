/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:17:27 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/09 04:53:33 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**recursion(char **map, t_tetrimino **tetriminos, int ti, t_pos points)
{
	while (recurse(&map, tetriminos, ti, points) == -1)
		map = map_increase(map);
	return (map);
}


int		recurse(char ***map, t_tetrimino **tetriminos, int ti, t_pos points)
{
	int		ret;
	char	**tmp_map;

	tmp_map = map_dup(*map);
	ret = try_place(&tmp_map, tetriminos, ti, points);
	if (ret == 1 && tetriminos[ti + 1])
		ret = recurse(&tmp_map, tetriminos, ti + 1, points);
	if (tetriminos[ti + 1] && ret == -1 && tmp_map[points.y] && tmp_map[points.y][points.x])
	{
		map_del(tmp_map);
		tmp_map = map_dup(*map);
		points.x++;
		ret = recurse(&tmp_map, tetriminos, ti, points);
	}
	if (ret == 1)
	{
		map_del(*map);
		*map = map_dup(tmp_map);
	}
	map_del(tmp_map);
	return (ret);
}

int		try_place(char ***map, t_tetrimino **tetriminos, int ti, t_pos points)
{
	int	ret;

	ret = 0;
	if (!tetriminos[ti])
		return (-1);
	while (ret == 0)
	{
		ret = check_map(*map, tetriminos[ti], ti, &points);
		points.x++;
	}
	return (ret);
}

char	**map_dup(char **map)
{
	int		i;
	char	**new_map;

	i = ft_strlen(map[0]);
	new_map = (char **)malloc(sizeof(char *) * (i + 1));
	new_map[i] = NULL;
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (new_map);
}

char	**map_increase(char **map)
{
	int		j;
	int		i;
	int		map_size;
	char	**new_map;

	map_size = ft_strlen(map[0]);
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
