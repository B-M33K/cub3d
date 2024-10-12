/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:55:37 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 17:39:59 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_key_press(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
	{
		ft_clear_all(g);
	}
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		g->p->walk_direction = 1;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		g->p->walk_direction = -1;
	else
		g->p->walk_direction = 0;
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		g->p->turn_direction = -1;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		g->p->turn_direction = 1;
	else
		g->p->turn_direction = 0;
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		g->p->rot_direction = -1;
	else if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		g->p->rot_direction = 1;
	else
		g->p->rot_direction = 0;
}
