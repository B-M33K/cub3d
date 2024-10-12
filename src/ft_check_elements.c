/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:55:08 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:14:43 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_elements(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->cub_file->line_count)
	{
		j = 0;
		while (g->cub_file->cub_file[i][j] == ' ' || \
		g->cub_file->cub_file[i][j] == '\t')
			j++;
		if (g->cub_file->cub_file[i][j] && \
		g->cub_file->cub_file[i][j + 1] && g->cub_file->cub_file[i][j + 2])
			ft_assign_elements(g->cub_file->cub_file[i][j], \
		g->cub_file->cub_file[i][j + 1], g->cub_file->cub_file[i][j + 2], g);
		i++;
	}
	if (g->cub_file->north == false || g->cub_file->south == false
		|| g->cub_file->west == false || g->cub_file->east == false
		|| g->cub_file->ceiling == false || g->cub_file->floor == false)
	{
		ft_putstr_fd("Error\nMissing elements\n", 2);
		ft_clean_all(g, g->cub_file);
		exit(0);
	}
	return (0);
}
