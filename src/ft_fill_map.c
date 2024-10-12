/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:24:53 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 16:58:37 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_player(t_game *g, int i, int j)
{
	if ((g->map->grid_fill[i][j] == 'N' || g->map->grid_fill[i][j] == 'S'
		|| g->map->grid_fill[i][j] == 'E' || g->map->grid_fill[i][j] == 'W')
		&& (g->map->grid_fill[i][j + 1] == '0'
		|| g->map->grid_fill[i][j - 1] == '0'
		|| g->map->grid_fill[i + 1][j] == '0'
		|| g->map->grid_fill[i - 1][j] == '0'))
		return (1);
	return (0);
}

static int	ft_closed(t_game *g, int i, int j)
{
	if ((g->map->grid_fill[i][j] == 'N'
		&& (g->p->x != i || g->p->y != j))
		|| (g->map->grid_fill[i][j] == 'E'
		&& (g->p->x != i || g->p->y != j))
		|| (g->map->grid_fill[i][j] == 'W'
		&& (g->p->x != i || g->p->y != j))
		|| (g->map->grid_fill[i][j] == 'S'
		&& (g->p->x != i || g->p->y != j)))
		return (1);
	else if (g->map->grid_fill[i][j] == ' ' || g->map->grid_fill[i][j] == '\t')
		return (0);
	return (1);
}

static void	ft_move_player(t_game *g, int i, int j)
{
	if (g->map->n == true)
		g->map->grid_fill[i][j] = 'N';
	else if (g->map->s == true)
		g->map->grid_fill[i][j] = 'S';
	else if (g->map->w == true)
		g->map->grid_fill[i][j] = 'W';
	else if (g->map->e == true)
		g->map->grid_fill[i][j] = 'E';
}

static int	ft_move_player_player(t_game *g, int i, int j)
{
	if (g->map->grid_fill[i][j + 1] == '0')
		ft_move_player(g, i, j + 1);
	else if (ft_closed(g, i, j + 1) == 0)
		return (0);
	if (g->map->grid_fill[i][j - 1] == '0')
		ft_move_player(g, i, j - 1);
	else if (ft_closed(g, i, j - 1) == 0)
		return (0);
	if (g->map->grid_fill[i + 1][j] == '0')
		ft_move_player(g, i + 1, j);
	else if (ft_closed(g, i + 1, j) == 0)
		return (0);
	if (g->map->grid_fill[i - 1][j] == '0')
		ft_move_player(g, i - 1, j);
	else if (ft_closed(g, i - 1, j) == 0)
		return (0);
	return (1);
}

int	ft_fill_map(t_game *g, bool player)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->map->height + 2)
	{
		j = -1;
		while (g->map->grid_fill[i][++j])
		{
			if (i > 0 && ft_check_player(g, i, j) == 1)
			{
				player = true;
				if (ft_move_player_player(g, i, j))
					i = 0;
				else
					return (ft_not_closed_and_clean(g), 0);
			}
		}
		i++;
	}
	if (player == false)
		return (ft_putstr_fd("Error\nInvalid map\n", 2),
			ft_clean_all(g, g->cub_file), exit(0), 0);
	return (1);
}
