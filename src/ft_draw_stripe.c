/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_stripe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:28:51 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 17:53:55 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_stripe(t_game *g, int i)
{
	t_var		v;
	uint32_t	*arr;

	v.m = g->rays[i].v_collision;
	v.t = g->textures[v.m][v.m * g->rays[i].right + (!v.m) * g->rays[i].down];
	v.j = 0;
	arr = (uint32_t *)v.t->pixels;
	v.wall_offset = (int)(SCREAN_HEIGHT / 2) - (g->rays[i].wall_height / 2);
	v.x_ratio = v.t->width / TILE_SIZE;
	v.y_ratio = v.t->height / g->rays[i].wall_height;
	v.t_x = (int) g->rays[i].x_offset * v.x_ratio;
	while (v.j < g->rays[i].wall_height)
	{
		v.y = (int) v.j + v.wall_offset;
		if (i >= 0 && v.y >= 0 && i < SCREAN_WIDTH && v.y < SCREAN_HEIGHT)
		{
			v.t_y = v.j * v.y_ratio;
			v.c = ft_rgba_color(ft_get_a(arr[v.t_y * v.t->width + v.t_x]),
					ft_get_b(arr[v.t_y * v.t->width + v.t_x]),
					ft_get_g(arr[v.t_y * v.t->width + v.t_x]),
					ft_get_r(arr[v.t_y * v.t->width + v.t_x]));
			mlx_put_pixel(g->image, i, v.y, v.c);
		}
		v.j++;
	}
}
