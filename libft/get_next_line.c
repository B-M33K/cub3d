/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:05:36 by obahi             #+#    #+#             */
/*   Updated: 2023/12/09 19:38:57 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*c;
	char	*line;
	char	*tmp;
	int		count;

	line = ft_strdup("");
	c = malloc(2);
	if (fd < 0 || read(fd, c, 0) == -1)
		return (free(line), free(c), NULL);
	count = read(fd, c, 1);
	if (count <= 0)
		return (free(line), free(c), NULL);
	while (count > 0)
	{
		*(c + 1) = 0;
		tmp = line;
		line = ft_strjoin(line, c);
		free(tmp);
		if (*c == '\n')
			break ;
		count = read(fd, c, 1);
	}
	free(c);
	return (line);
}
