/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:09:55 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 20:48:04 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_update_player(t_game *g)
{
	double	x;
	double	y;
	int		step;

	g->p->rot_angle += g->p->rot_direction * g->p->rot_speed;
	g->p->rot_angle = ft_norm_angle(g->p->rot_angle);
	step = g->p->walk_direction * g->p->mv_speed;
	x = g->p->x + cos(g->p->rot_angle) * step;
	y = g->p->y + sin(g->p->rot_angle) * step;
	if (g->map->grid[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == '0')
	{
		g->p->x = x;
		g->p->y = y;
	}
	step = g->p->turn_direction * g->p->mv_speed;
	x = g->p->x + cos(g->p->rot_angle + M_PI / 2) * step;
	y = g->p->y + sin(g->p->rot_angle + M_PI / 2) * step;
	if (g->map->grid[(int)y / TILE_SIZE][(int)x / TILE_SIZE] == '0')
	{
		g->p->x = x;
		g->p->y = y;
	}
}
