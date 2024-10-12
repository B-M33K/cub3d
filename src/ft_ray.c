/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 03:24:20 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 21:21:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_ray	ft_ray(double ray_angle)
{
	t_ray	ray;

	ray.ray_angle = ft_norm_angle(ray_angle);
	ray.x_collision = -1;
	ray.y_collision = -1;
	ray.d = 0;
	ray.down = (ray.ray_angle > 0 && ray.ray_angle < M_PI);
	ray.right = (ray.ray_angle < M_PI / 2 || ray.ray_angle > 3 * M_PI / 2);
	ray.v_collision = 0;
	return (ray);
}
