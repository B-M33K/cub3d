/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:37:12 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 21:05:49 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_minimap(t_game *g)
{
	int	c[2];
	int	i;
	int	j;

	j = -1;
	c[1] = g->p->y - (MINI_MAP_HEIGHT / 2);
	while (++j < MINI_MAP_HEIGHT)
	{
		c[0] = g->p->x - (MINI_MAP_WIDTH / 2);
		i = -1;
		while (++i < MINI_MAP_WIDTH)
		{
			if (!ft_out_of_bound(g->map, c[0], c[1]))
			{
				if (ft_is_wall(g->map, c[1] / TILE_SIZE, c[0] / TILE_SIZE))
					mlx_put_pixel(g->image, i, j, 0x3a0956ff);
				else
					mlx_put_pixel(g->image, i, j, g->floor);
			}
			else
				mlx_put_pixel(g->image, i, j, 0x000000ff);
			c[0]++;
		}
		c[1]++;
	}
}
