/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revised_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/02 16:39:08 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_map(char **map, t_tetrimino **tetriminos, int mmv, int ti)
{
	int				**coordinates;
	t_pos			points;

	points.map_x = 0;
	points.map_y = 0;
	points.i = 0;
	coordinates = NULL;
	coordinates = coord_init(coordinates);
	first_block(map, tetriminos, &points, ti);
	mmv = 0;
	while (points.i < 4)
	{
		//ft_putendl("Hector is Cool");
		ft_putnbr(points.i);
		ft_putchar('\n');
		//ft_putnbr();
		/*if (map[points.map_y][points.map_x] == '\0' && points.map_y < mmv)
		{
			points.map_x = 0;
			points.map_y++;
			ft_putendl("stuff");
		}
		//Modify this if loop, it serves no purpose, maybe change it to
		//still check for the correct stuff in the map
		else if (points.map_y == mmv && map[points.map_y][points.map_x] == '\0')
			return (-1);*/
		ft_putendl("after if");
		if (!transfer(map, &points, coordinates))
			return (-1);
		points.i++;
		map_increment(tetriminos[ti], &points);
	}
	ft_putendl("End of check_map");
	map = place_block(map, ti, coordinates, &points);
	ft_putstrx2(map);
	return (0);
}

int		**transfer(char **map, t_pos *points, int **coordinates)
{
	int	i;

	i = 0;
	if (map[points->map_y][points->map_x] == '.')
	{
		coordinates[points->i][0] = points->map_x;
		coordinates[points->i][1] = points->map_y;
		ft_putendl("transfer");
	}
	else
	{
		while (coordinates[i])
			free(coordinates[i++]);
		free(coordinates);
		coordinates = NULL;
	}
	ft_putendl("transferx2");
	return (coordinates);
}

int		**coord_init(int **coordinates)
{
	int		i;

	coordinates = (int **)malloc(sizeof(int *) * (5));
	coordinates[4] = NULL;
	i = 0;
	while (i < 4)
	{
		coordinates[i] = (int *)malloc(sizeof(int) * (3));
		coordinates[i][2] = '\0';
		i++;
	}
	return (coordinates);
}
