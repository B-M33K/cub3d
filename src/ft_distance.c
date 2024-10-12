/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distance.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:30:20 by obahi             #+#    #+#             */
/*   Updated: 2023/12/10 20:33:04 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	ft_distance(double xa, double ya, double xb, double yb)
{
	return (sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb)));
}
