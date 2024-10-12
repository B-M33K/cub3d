/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:29:19 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 20:46:02 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_draw(t_game *g)
{
	ft_draw_background(g);
	ft_render_walls(g);
	ft_draw_minimap(g);
	ft_draw_player(g);
}
