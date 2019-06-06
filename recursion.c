/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:47:40 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/06 08:41:25 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char	**recursion(char **map, t_tetrimino **tetriminos, int ti, int *prev_start)
// {
// 	char	**tmp_map;
// 	int		i;
// 	int		j;
// 	int		size;
	
// 	if (tetriminos[ti])
// 	{
// 		size = ft_strlen(map[0]);
// 		tmp_map = (char **)malloc(sizeof(char *) * (size + 1));
// 		tmp_map[size] = NULL;
// 		i = -1;
// 		while (++i < size)
// 			tmp_map[i] = ft_strdup(map[i]);
// 		i = 0;
// 		j = -1;
// 		while (map[i] && map[i][++j] != '.')
// 		{
// 			if (j == size)
// 			{
// 				j = -1;
// 				i++;
// 			}
// 		}
// 		prev_start[0] = j - 1;
// 		prev_start[1] = i;
// 		while (i == 0 || prev_start[2] == 0)
// 		{
// 			prev_start[0]++;
// 			ft_putstr("---");
// 			prev_start = check_map(tmp_map, tetriminos[ti], ti, prev_start);
// 			ft_putnbr(ti);
// 			ft_putstr(" ATTEMPT ");
// 			ft_putnbr(i);
// 			ft_putendl(" ---\n");
// 			i++;
// 			ft_putstrx2(tmp_map);
// 		ft_putendl("\n");
// 		}
// 		if (prev_start[2] == 1)
// 		{
// 			(ti)++;
// 			tmp_map = recursion(tmp_map, tetriminos, ti, prev_start);
// 			while (prev_start[2] != 1 && (ti) - 1 < size)
// 			{
// 				(ti)++;
// 				tmp_map = recursion(tmp_map, tetriminos, ti, prev_start);
// 			}
// 			if (prev_start[2] == 1)
// 				map = tmp_map;
// 		}
// 		if (prev_start[2] == -1)
// 			map = map_increase(map, size);
// 		i = 0;
// 		while (tmp_map[i])
// 				free(tmp_map[i++]);
// 			free(tmp_map);
// 			tmp_map = NULL;
// 	}
// 	return(map);
// }

char	**recursion(char **map, t_tetrimino **tetriminos, int ti, int *prev_start)
{
	char	**tmp_map;
	int		size;
	int		i;
	int		j;
	int		placed;

	size = ft_strlen(map[0]);
	tmp_map = (char **)malloc(sizeof(char *) * (size + 1));
	tmp_map[size] = NULL;
	i = -1;
	while (++i < size)
		tmp_map[i] = ft_strdup(map[i]);
	placed = 0;
	i = -1;
	ti = -1;
	while (tetriminos[++ti] || i == -1)
	{
		i = 0;
		j = -1;
		while (tmp_map[i] && tmp_map[i][++j] != '.')
		{
			if (j == size)
			{
				j = -1;
				i++;
			}
		}
		prev_start[0] = j;
		prev_start[1] = i;
		i = 0;
		if (tetriminos[ti]->placed == 0)
		{
			while (i == 0 || prev_start[2] == 0)
			{
				prev_start = check_map(tmp_map, tetriminos[ti], ti, prev_start);
				prev_start[0]++;
				i++;
			}
			if (prev_start[2] == 1)
			{
				tetriminos[ti]->placed = 1;
				tmp_map = recursion(tmp_map, tetriminos, 0, prev_start);
				ft_putchar('a' + ti);
				ft_putchar('\n');
				ft_putstrx2(tmp_map);
				ft_putchar('\n');
				if (prev_start[2] == -1)
				{
					tetriminos[ti]->placed = 0;
					ti++;
				}
			}
		}
		else
			placed++;
	}
	if (prev_start[2] == -1 && placed == 1 && !tetriminos[ti])
	{
		tetriminos[ti]->placed = 0;
		tmp_map = map_increase(map, size);
		map = recursion(tmp_map, tetriminos, 0, prev_start);
	}
	while (tmp_map[i])
		free(tmp_map[i++]);
	free(tmp_map);
	tmp_map = NULL;
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
	return (new_map);
}
