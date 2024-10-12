/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_new_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:05:01 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 11:41:23 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_new_image(t_game *g)
{
	g->image = mlx_new_image(g->mlx, SCREAN_WIDTH, SCREAN_HEIGHT);
	if (!g->image)
	{
		mlx_close_window(g->mlx);
		ft_putendl_fd(mlx_strerror(mlx_errno), 2);
		exit(1);
	}
	ft_memset(g->image->pixels, 255,
		SCREAN_WIDTH * SCREAN_HEIGHT * sizeof(int));
	if (mlx_image_to_window(g->mlx, g->image, 0, 0) == -1)
	{
		mlx_close_window(g->mlx);
		mlx_delete_image(g->mlx, g->image);
		ft_putendl_fd(mlx_strerror(mlx_errno), 2);
		exit(1);
	}
}
