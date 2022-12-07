/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduarodr <eduarodr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 13:17:37 by eduarodr          #+#    #+#             */
/*   Updated: 2022/11/30 15:42:23 by eduarodr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	saved[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	line = 0;
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0 || fd >= FOPEN_MAX)
	{
		while (fd >= 0 && fd < FOPEN_MAX && saved[fd][i])
			saved[fd][i++] = 0;
		return (NULL);
	}
	while (saved[fd][0] || read(fd, saved[fd], BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, saved[fd]);
		if (ft_strclean(saved[fd]))
			break ;
	}
	return (line);
}
