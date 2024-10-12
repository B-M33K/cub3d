/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_is_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:48:41 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:15:02 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_is_player(t_game *g, int i, int j)
{
	if (g->map->grid_fill[i][j] == 'N' || g->map->grid_fill[i][j] == 'S'
		|| g->map->grid_fill[i][j] == 'E' || g->map->grid_fill[i][j] == 'W')
		return (1);
	return (0);
}

int	ft_check_player_around(t_game *g, int i, int j)
{
	if ((g->map->grid_fill[i][j] == 'N' || g->map->grid_fill[i][j] == 'S'
		|| g->map->grid_fill[i][j] == 'E' || g->map->grid_fill[i][j] == 'W')
		&& ((g->map->grid_fill[i][j + 1] != '1' && !ft_is_player(g, i, j + 1))
		|| (g->map->grid_fill[i][j - 1] != '1' && !ft_is_player(g, i, j - 1))
		|| (g->map->grid_fill[i + 1][j] != '1' && !ft_is_player(g, i + 1, j))
		|| (g->map->grid_fill[i - 1][j] != '1' && !ft_is_player(g, i - 1, j))))
		return (1);
	return (0);
}

int	ft_check_is_closed(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map->grid_fill[i])
	{
		j = -1;
		while (g->map->grid_fill[i][++j])
			if (ft_check_player_around(g, i, j) == 1)
				return (ft_not_closed_and_clean(g), 0);
		i++;
	}
	return (0);
}
