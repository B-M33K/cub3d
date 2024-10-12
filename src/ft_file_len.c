/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:41:29 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/12 21:11:27 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_file_len(t_game *g, char *cub_file)
{
	int		count;
	int		fd;
	char	*mappy;

	count = 0;
	fd = open(cub_file, O_RDONLY);
	if (fd <= -1)
		return (-1);
	mappy = get_next_line(fd);
	if (mappy == NULL)
		return (close(fd), free(mappy), ft_clean_all(g, g->cub_file),
			exit(0), 0);
	if (!mappy)
		return (close(fd), exit(0), 0);
	while (mappy)
	{
		free(mappy);
		mappy = get_next_line(fd);
		count++;
	}
	close(fd);
	return (count);
}
