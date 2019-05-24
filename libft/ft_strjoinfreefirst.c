/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreefirst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:32:20 by vdauverg          #+#    #+#             */
/*   Updated: 2019/05/11 14:33:15 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfreefirst(char *s1, char *s2)
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
}
