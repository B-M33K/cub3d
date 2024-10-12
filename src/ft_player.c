/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:11:35 by obahi             #+#    #+#             */
/*   Updated: 2023/12/14 10:55:47 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_player_init(t_game *g, int i, int j)
{
	g->p->y = i;
	g->p->x = j;
	g->p->mv_speed = 2;
	if (g->map->n)
		g->p->rot_angle = 3 * (M_PI / 2);
	else if (g->map->s)
		g->p->rot_angle = M_PI / 2;
	else if (g->map->w)
		g->p->rot_angle = M_PI;
	else
		g->p->rot_angle = 0;
	g->p->rot_speed = 2 * (M_PI / 180);
	g->p->fov = 60 * M_PI / 180;
}
