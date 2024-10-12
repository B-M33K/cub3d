/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:42:50 by obahi             #+#    #+#             */
/*   Updated: 2023/12/14 10:55:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_parsing(t_game *g, char *argv)
{
	bool	player;

	player = false;
	if (ft_get_all_cub_file(g, argv) == NULL)
		return (exit(0));
	ft_check_elements(g);
	ft_get_map(g);
	ft_fill_map(g, player);
	g->map->grid[(int)g->p->y][(int)g->p->x] = '0';
	ft_check_is_closed(g);
	ft_parse_and_get_textures(g);
	ft_parse_colors(g);
	g->ceiling = ft_rgba_color(g->map->ceiling_r,
			g->map->ceiling_g, g->map->ceiling_b, 0xff);
	g->floor = ft_rgba_color(g->map->floor_r, g->map->floor_g,
			g->map->floor_b, 0xff);
	g->map->width *= TILE_SIZE;
	g->map->height *= TILE_SIZE;
	g->p->x *= TILE_SIZE;
	g->p->y *= TILE_SIZE;
	g->p->x += TILE_SIZE / 2;
	g->p->y += TILE_SIZE / 2;
}

int	main(int argc, char **argv)
{
	t_game		*g;
	t_map		*map;
	t_cub_file	*cub_file;

	if (argc != 2)
		return (0);
	cub_file = ft_calloc(sizeof(t_cub_file), 1);
	map = ft_calloc(sizeof(t_map), 1);
	g = ft_game_init(*(argv + 1), cub_file, map);
	ft_parsing (g, argv[1]);
	if (ft_mlx_load_textures(g) < 0)
	{
		ft_clean_all(g, g->cub_file);
		exit(1);
	}
	ft_rays_init(g);
	ft_mlx_init(g);
	ft_mlx_new_image(g);
	mlx_loop_hook(g->mlx, ft_key_press, g);
	mlx_loop_hook(g->mlx, ft_hook, g);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	free(g);
}
