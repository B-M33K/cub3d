/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_cub_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:35:06 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/12 21:08:18 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_cub_file	*ft_get_all_cub_file(t_game *g, char *file)
{
	int		i;
	int		fd;

	if (ft_check_cub_ext(file) == 1)
		return (NULL);
	g->cub_file->line_count = ft_file_len(g, file);
	if (g->cub_file->line_count <= 0)
		return (0);
	fd = open(file, O_RDWR);
	if (fd <= -1)
		return (ft_putstr_fd("Error\n.cub file does not exist\n",
				2), close(fd), free(g->cub_file), NULL);
	g->cub_file->cub_file = ft_calloc(g->cub_file->line_count + 1, \
							sizeof(char *));
	if (!g->cub_file->cub_file)
		return (close(fd), free(g->cub_file), NULL);
	i = 0;
	while (i < g->cub_file->line_count)
		g->cub_file->cub_file[i++] = ft_strtrim(get_next_line(fd), "\n");
	g->cub_file->cub_file[i] = NULL;
	close(fd);
	return (g->cub_file);
}
