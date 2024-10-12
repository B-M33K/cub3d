/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:49:23 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 18:05:08 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

#include "../include/cub3d.h"

void	ft_draw_player(t_game *g)
{
	double	rot_angle;
	int		x;
	int		y;
	int		i;
	int		j;

	x = MINI_MAP_WIDTH / 2;
	y = MINI_MAP_HEIGHT / 2;
	rot_angle = g->p->rot_angle;
	i = -1;
	while (++i <= 10)
	{
		j = -1;
		while (++j <= 10)
			mlx_put_pixel(g->image, x + j - 5, y + i - 5, 0xff0000ff);
	}
	mlx_put_pixel(g->image, x + 20 * cos(rot_angle),
		y + 20 * sin(rot_angle), 0xff0000ff);
}
