/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/28 21:29:37 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	safe_exit(int fd)
{
	(fd) ? close(fd) : 0;
	ft_putstr("usage: ./fillit source_file\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_tetrimino **tetriminos;
	int			i;
	int			j;
	int			k;
	int			l;

	if (argc == 2)
	{
		tetriminos = read_input(argv[1]);
		i = 0;
		while (tetriminos[i] && tetriminos[i]->placed != -1)
		{
			j = 0;
			while (j < 4)
			{
				k = 0;
				while (k < 4)
				{
					l = 0;
					while (l < 4)
					{
						if (tetriminos[i]->blocks[l].x == k && tetriminos[i]->blocks[l].y == j)
						{
							write(1, "#", 1);
							break ;
						}
						l++;
					}
					if (l == 4)
						write(1, ".", 1);
					k++;
				}
				write(1, "\n", 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		safe_exit(0);

	return (0);
}
