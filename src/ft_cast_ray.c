/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_ray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:46:48 by obahi             #+#    #+#             */
/*   Updated: 2023/12/14 11:03:36 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cast_ray(t_game *g, int i)
{
	double	d[6];
	int		offset;
	double	d_projection_plan;
	double	perp_distance;
	int		j;

	offset = 3;
	j = 0;
	ft_cast_h_ray(g, i, d);
	ft_cast_v_ray(g, i, d + offset);
	if (d[2] > d[2 + offset])
		j += offset;
	g->rays[i].d = d[2 + j];
	g->rays[i].x_collision = d[j];
	g->rays[i].y_collision = d[j + 1];
	g->rays[i].v_collision = (j != 0);
	if (g->rays[i].v_collision)
		g->rays[i].x_offset = fmod(g->rays[i].y_collision, TILE_SIZE);
	else
		g->rays[i].x_offset = fmod(g->rays[i].x_collision, TILE_SIZE);
	perp_distance = g->rays[i].d * cos(g->rays[i].ray_angle - g->p->rot_angle);
	d_projection_plan = (g->map->width / 2) / tan(g->p->fov / 2);
	g->rays[i].wall_height = (TILE_SIZE / perp_distance) * d_projection_plan;
}
