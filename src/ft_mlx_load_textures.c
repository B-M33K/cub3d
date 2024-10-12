/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_load_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:14:31 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 17:45:22 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_mlx_load_textures(t_game *g)
{
	int	ret;
	int	i;
	int	j;

	ret = 0;
	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			g->textures[i][j] = mlx_load_png(g->tex[i][j]);
			if (!g->textures[i][j])
				ret --;
			j++;
		}
		i++;
	}
	if (ret < 0)
		ft_mlx_delete_tex(g);
	return (ret);
}
