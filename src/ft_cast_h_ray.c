/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_h_ray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 23:07:02 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 20:25:14 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cast_h_ray(t_game *g, int i, double d[3])
{
	double	col[2];
	double	step[2];
	int		hit;
	int		k;

	hit = 0;
	col[1] = (floor(g->p->y / TILE_SIZE) + g->rays[i].down) * TILE_SIZE;
	col[0] = g->p->x + (col[1] - g->p->y) / tan(g->rays[i].ray_angle);
	step[1] = ((g->rays[i].down) * 2 - 1) * TILE_SIZE;
	step[0] = step[1] / tan(g->rays[i].ray_angle);
	k = -1 * (!g->rays[i].down);
	while (!hit && !ft_out_of_bound(g->map, col[0], col[1]))
	{
		hit = ft_is_wall(g->map, col[1] / TILE_SIZE + k, col[0] / TILE_SIZE);
		if (hit)
			ft_memmove(d, col, 2 * sizeof(double));
		else
		{
			col[0] += step[0];
			col[1] += step[1];
		}
	}
	d[2] = hit * ft_distance(g->p->x, g->p->y, d[0], d[1]) + (!hit) * INT_MAX;
}
