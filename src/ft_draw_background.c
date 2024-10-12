/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:27:29 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 21:15:34 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw_background(t_game *g)
{
	int	half_screen;
	int	i;
	int	j;

	half_screen = SCREAN_HEIGHT / 2;
	i = -1;
	while (++i < half_screen)
	{
		j = -1;
		while (++j < SCREAN_WIDTH)
			mlx_put_pixel(g->image, j, i, g->ceiling);
	}
	i = -1;
	while (++i < half_screen)
	{
		j = -1;
		while (++j < SCREAN_WIDTH)
			mlx_put_pixel(g->image, j, half_screen + i, g->floor);
	}
}
