/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:01:37 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 11:04:11 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_mlx_init(t_game *g)
{
	g->mlx = mlx_init(SCREAN_WIDTH, SCREAN_HEIGHT, "cub3d", 0);
	if (!g->mlx)
	{
		ft_putendl_fd(mlx_strerror(mlx_errno), 2);
		exit(1);
	}
}
