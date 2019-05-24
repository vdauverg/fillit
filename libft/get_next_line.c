/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:09:37 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/15 21:05:08 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*ft_strjoinfreefirst(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (s1 && s2 && (s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		i = 0;
		while ((s1[i] ? s3[i] = s1[i] : 0))
			i++;
		ft_strdel(&s1);
		j = 0;
		while ((s2[j] ? s3[i + j] = s2[j] : 0))
			j++;
		s3[i + j] = 0;
		return (s3);
	}
	else
		return (NULL);
}*/

int		get_next_line(const int fd, char **line)
{
	static char	*fdlist[4096];
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			isread;
	int			check;

	if (!line || fd < 0 || fd > 4096 || !(*line = ft_strnew(0)))
		return (-1);
	check = 0;
	ft_strclr(buff);
	(fdlist[fd] && *fdlist[fd] && (check = 1) &&
		(*line = ft_strjoin(fdlist[fd], *line))) ? ft_strdel(&(fdlist[fd])) : 0;
	if (!ft_strchr(*line, '\n'))
	{
		while (!ft_strchr(buff, '\n')
				&& (isread = read(fd, buff, BUFF_SIZE)) > 0
				&& !(buff[isread] = '\0')
				&& (*line = ft_strjoinfreefirst(*line, buff)))
			check = 1;
	}
	tmp = ft_strchr(*line, '\n');
	(tmp && *tmp && !(*tmp = '\0') && tmp++) ?
		fdlist[fd] = ft_strdup(tmp) : 0;
	return ((**line || check == 1) ? 1 : isread);
}
