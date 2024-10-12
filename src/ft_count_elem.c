/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:44:16 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:16:09 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_count_elements2(t_game *g, int count, int i, int j)
{
	t_cub_file	*cub;

	cub = g->cub_file;
	if (cub->cub_file[i][j] == 'N' && cub->cub_file[i][j + 1] == 'O'
		&& cub->cub_file[i][j + 2] == ' ')
		count++;
	if (cub->cub_file[i][j] == 'S' && cub->cub_file[i][j + 1] == 'O'
		&& cub->cub_file[i][j + 2] == ' ')
		count++;
	if (cub->cub_file[i][j] == 'W' && cub->cub_file[i][j + 1] == 'E'
		&& cub->cub_file[i][j + 2] == ' ')
		count++;
	if (cub->cub_file[i][j] == 'E' && cub->cub_file[i][j + 1] == 'A'
		&& cub->cub_file[i][j + 2] == ' ')
		count++;
	if (cub->cub_file[i][j] == 'C' && cub->cub_file[i][j + 1] == ' ')
		count++;
	if (cub->cub_file[i][j] == 'F' && cub->cub_file[i][j + 1] == ' ')
		count++;
	return (count);
}

int	ft_count_elements(t_game *g, int count)
{
	int	i;
	int	j;

	i = -1;
	while (g->cub_file->cub_file[++i])
	{
		j = -1;
		while (g->cub_file->cub_file[i][++j])
			count = ft_count_elements2(g, count, i, j);
		if (count == 6)
			return (i);
	}
	return (0);
}
