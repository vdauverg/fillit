/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:59:53 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/06 07:21:21 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_exit(t_tetrimino *tmp, t_tetrimino **tetriminos,
				int num, int fd)
{
	(tmp) ? free(tmp) : 0;
	while (--num >= 0)
		free(tetriminos[num]);
	free(tetriminos);
	safe_exit(fd);
}

int			read_piece(int fd, t_tetrimino **tmp)
{
	int		i;
	int		len;
	char	*line;
	char	*piece;

	piece = "";
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		(*line) ? len = ft_strlen(line) : 0;
		if (*line && len == 4)
			piece = ft_strjoin(piece, line);
		else if (len == 4 && i == 4)
		{
			ft_strdel(&line);
			*tmp = check_piece(piece, fd);
			return (1);
		}
		else
			return (0);
		(line) ? ft_strdel(&line) : 0;
		i++;
	}
	return (2);
}

t_tetrimino	**read_input(char *input)
{
	int			fd;
	int			num;
	int			check;
	t_tetrimino	*tmp;
	t_tetrimino	**tetriminos;

	((fd = open(input, O_RDONLY)) <= 0) ? safe_exit(0) : 0;
	tetriminos = (t_tetrimino **)malloc(sizeof(t_tetrimino *) * 27);
	tetriminos[26] = NULL;
	num = 0;
	tmp = NULL;
	while ((check = read_piece(fd, &tmp)) != 2 || (check == 2 && num == 0))
	{
		if (check == 1)
			tetriminos[num] = tmp;
		else
			free_exit(tmp, tetriminos, num, fd);
		tmp = NULL;
		tetriminos[num]->placed = 0;
		num++;
	}
	close(fd);
	while (num < 26)
		tetriminos[num++] = NULL;
	return (tetriminos);
}
