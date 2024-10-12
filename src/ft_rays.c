/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 04:25:36 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 18:06:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rays(t_game *g)
{
	double	ray_angle;
	int		i;

	i = 0;
	ray_angle = (g->p->rot_angle - (g->p->fov / 2));
	while (i < g->num_rays)
	{
		g->rays[i] = ft_ray(ray_angle);
		ray_angle += g->p->fov / (double)g->num_rays;
		i++;
	}
}
