/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   he_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 02:18:38 by hecampbe          #+#    #+#             */
/*   Updated: 2019/05/27 01:04:02 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	static char **map;
	int map_size;
	t_tetrimino **tetriminos;
	int ti;

	if (argc == 2)
	{
		map = NULL;
		map_size = 4;
		ti = 0;
		tetriminos = read_input(argv[1]);
		check_map(map, tetriminos, map_size, ti);
	}
	return (0);
}