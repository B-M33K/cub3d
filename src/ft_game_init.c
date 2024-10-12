/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:37:05 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 18:05:47 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_struct_cub_file(t_cub_file *cub_file)
{
	cub_file->north = false;
	cub_file->south = false;
	cub_file->west = false;
	cub_file->east = false;
	cub_file->floor = false;
	cub_file->ceiling = false;
}

void	ft_init_struct_map(t_map *map)
{
	map->floor_r = -1;
	map->floor_g = -1;
	map->floor_b = -1;
	map->ceiling_r = -1;
	map->ceiling_g = -1;
	map->ceiling_b = -1;
}

t_game	*ft_game_init(char *file, t_cub_file *cub_file, t_map *map)
{
	t_game	*g;

	(void) file;
	g = malloc(sizeof(t_game));
	if (!g)
		return (0);
	ft_memset(g, 0, sizeof(t_game));
	ft_init_struct_cub_file(cub_file);
	ft_init_struct_map(map);
	g->cub_file = cub_file;
	g->map = map;
	g->num_rays = SCREAN_WIDTH;
	return (g);
}
