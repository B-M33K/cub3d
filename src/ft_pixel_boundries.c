/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_boundries.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 20:24:24 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 20:28:09 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_out_of_bound(t_map	*map, double x, double y)
{
	return (x < 0 || x >= map->width || y < 0 || y >= map->height);
}

int	ft_is_wall(t_map *map, int x, int y)
{
	return (map->grid[x][y] != '0');
}
