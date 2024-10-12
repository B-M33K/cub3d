/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:47:06 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 17:39:23 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_clear_all(t_game *g)
{
	ft_free2(g->map->grid);
	ft_free2(g->map->grid_fill);
	free(g->map);
	free(g->p);
	free(g->rays);
	ft_free2(g->cub_file->cub_file);
	free(g->cub_file);
	ft_mlx_delete_tex(g);
	free(g->tex[0][0]);
	free(g->tex[0][1]);
	free(g->tex[1][0]);
	free(g->tex[1][1]);
	mlx_delete_image(g->mlx, g->image);
	mlx_close_window(g->mlx);
}
