/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:06:01 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 21:06:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_cast_rays(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->num_rays)
	{
		ft_cast_ray(g, i);
		i++;
	}
}
