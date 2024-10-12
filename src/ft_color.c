/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:08:09 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 20:45:37 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_if_only_one_num(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		while (rgb[i][j] >= '0' && rgb[i][j] <= '9')
			j++;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		if (rgb[i][j] != '\0')
			return (ft_putstr_fd("Error\nToo many numbers\n", 2), 0);
		i++;
	}
	return (1);
}

int	ft_rgba_color(int r, int g, int b, int a)
{
	int	color;

	color = 0;
	color = r << 24 | g << 16 | b << 8 | a;
	return (color);
}
