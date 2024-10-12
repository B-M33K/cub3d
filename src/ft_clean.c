/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:26:36 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/12 21:07:20 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_map(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		free(map);
	}
}

void	ft_clean_all_rgb(char **rgb, char **rgb_final)
{
	int	i;

	i = -1;
	if (rgb)
	{
		while (rgb[++i])
			free(rgb[i]);
		free(rgb);
	}
	i = -1;
	if (rgb_final)
	{
		while (rgb_final[++i])
			if (rgb_final[i])
				free(rgb_final[i]);
		free(rgb_final);
	}
}

void	ft_clean_all_rgb_(char **rgb, char **rgb_final, t_game *g)
{
	int	i;

	i = -1;
	if (rgb)
	{
		while (rgb[++i])
			free(rgb[i]);
		free(rgb);
	}
	i = -1;
	if (rgb_final)
	{
		while (rgb_final[++i])
			if (rgb_final[i])
				free(rgb_final[i]);
		free(rgb_final);
	}
	ft_clean_all(g, g->cub_file);
	exit(0);
}

void	ft_clean_all(t_game *g, t_cub_file *cub_file)
{
	if (g)
	{
		if (g->tex[0][0])
			free(g->tex[0][0]);
		if (g->tex[0][1])
			free(g->tex[0][1]);
		if (g->tex[1][0])
			free(g->tex[1][0]);
		if (g->tex[1][1])
			free(g->tex[1][1]);
		if (g->map->grid)
			ft_free_map(g->map->grid);
		if (g->map->grid_fill)
			ft_free_map(g->map->grid_fill);
	}
	if (cub_file->cub_file)
		ft_free_map(cub_file->cub_file);
	free(cub_file);
	if (g->p)
		free(g->p);
	if (g)
		free(g);
}
