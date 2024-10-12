/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_rgb_c_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:06:17 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:13:25 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_assign_rgb_c_f(t_game *g, char **rgb_final, int flag)
{
	if (flag == 1)
	{
		g->map->ceiling_r = ft_atoi(rgb_final[0]);
		g->map->ceiling_g = ft_atoi(rgb_final[1]);
		g->map->ceiling_b = ft_atoi(rgb_final[2]);
		if (g->map->ceiling_r < 0 || g->map->ceiling_r > 255)
			return (0);
		if (g->map->ceiling_g < 0 || g->map->ceiling_g > 255)
			return (0);
		if (g->map->ceiling_b < 0 || g->map->ceiling_b > 255)
			return (0);
	}
	else
	{
		g->map->floor_r = ft_atoi(rgb_final[0]);
		g->map->floor_g = ft_atoi(rgb_final[1]);
		g->map->floor_b = ft_atoi(rgb_final[2]);
		if (g->map->floor_r < 0 || g->map->floor_r > 255)
			return (0);
		if (g->map->floor_g < 0 || g->map->floor_g > 255)
			return (0);
		if (g->map->floor_b < 0 || g->map->floor_b > 255)
			return (0);
	}
	return (1);
}
