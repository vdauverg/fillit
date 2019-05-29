#include "fillit.h"

char		map_increment(char **map, int max_map_value, t_tetrimino **tetriminos, int i, int ti, int map_x, int map_y)
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;

	x = tetriminos[ti] -> blocks[i].x;
	y = tetriminos[ti] -> blocks[i].y;
	tmp_x = x;
	tmp_y = y;
	if (y > tmp_y)
		map_y++;
	if (x > tmp_x)
		map_x++;
	if (map_x > max_map_value || map_y > max_map_value)
		return (1);
	if (x < tmp_x)
		map_x--;
	if (map[map_y][map_x] != '.')
		return (1);
	return (map[map_y][map_x]);
}
//First block will be checked before this function
