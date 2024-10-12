/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_inits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:10:11 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 18:07:00 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rays_init(t_game *g)
{
	g->rays = malloc((g->num_rays) * sizeof(t_ray));
	if (!g->rays)
		return ;
	ft_memset(g->rays, 0, (g->num_rays) * sizeof(t_ray));
	ft_rays(g);
}
