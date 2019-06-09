/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:17:27 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/09 04:20:44 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int	recursion(char ***map, t_tetrimino **tetriminos, int ti, t_pos points)
// {
// 	char	**tmp_map;
// 	int		ret;

// 	ret = 0;
// 	tmp_map = map_dup(*map);
// 	ret = check_map(tmp_map, tetriminos[ti], ti, &points);
// 	while (ret == 0)
// 	{
// 		points.x++;
// 		ret = check_map(tmp_map, tetriminos[ti], ti, &points);
// 	}
// 	if (ret == 1)
// 	{
// 		while (tetriminos[++ti] && (ret = recursion(&tmp_map, tetriminos, ti, points)) == -1)
// 		{
// 			ti--;
// 			points.x++;
// 			if (!tmp_map[points.y + 1] && !tmp_map[points.y][points.x])
// 				break ;
// 		}
// 		if (ret == 1)
// 		{
// 			ti--;
// 			map_del(*map);
// 			*map = map_dup(tmp_map);
// 			map_del(tmp_map);
// 			return (1);
// 		}
// 	}
// 	if (!(*map)[points.y] || ((*map)[points.y] && !((*map)[points.y][points.x])))
// 	{
// 		if (ti == 0)
// 		{
// 			points.x = 0;
// 			points.y = 0;
// 			*map = map_increase(*map);
// 			ret = recursion(map, tetriminos, ti, points);
// 		}
// 	}
// 	map_del(tmp_map);
// 	return (ret);
// }

int		recursion(char ***map, t_tetrimino **tetriminos, int ti, t_pos points)
{
	int		ret;
	char	**tmp_map;

	points.rec++;
	tmp_map = map_dup(*map);
	ret = try_place(&tmp_map, tetriminos, ti, points);
	while (tetriminos[ti])
	{
			while (tetriminos[ti] && ret == 1)
			{
				tetriminos[ti]->placed = 1;
				while (tetriminos[ti] && tetriminos[ti]->placed == 1)
					ti++;
				ret = recursion(&tmp_map, tetriminos, ti, points);
				map_del(*map);
				*map = map_dup(tmp_map);
			}
			while (tetriminos[ti] && ret == -1)
			{
				tetriminos[ti]->placed = 0;
				if (ti == 0 && points.rec == 0)
				{
					free(tmp_map);
					*map = map_increase(*map);
					tmp_map = map_dup(*map);
					ret = try_place(&tmp_map, tetriminos, ti, points);
				}
				if (ti > 0)
					ret = recursion(&tmp_map, tetriminos, --ti, points);
			}
	}
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
