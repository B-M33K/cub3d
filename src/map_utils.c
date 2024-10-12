/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:39:02 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 18:08:02 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_copy_map(t_game *g)
{
	int	i;
	int	j;

	g->map->grid_fill = ft_calloc((g->map->height + 3), sizeof(char *));
	if (!g->map->grid_fill)
		return (ft_putstr_fd("Error\nMalloc error!\n", 2),
			ft_clean_all(g, NULL), exit(0));
	i = -1;
	while (++i < g->map->height + 2)
	{
		g->map->grid_fill[i] = ft_calloc((g->map->width + 2), sizeof(char));
		j = -1;
		while (++j <= (int)g->map->width)
			g->map->grid_fill[i][j] = '2';
		g->map->grid_fill[i][g->map->width + 1] = '\0';
	}
	i = 0;
	j = 1;
	while (++i < g->map->height + 1 && j++)
		ft_memcpy(g->map->grid_fill[i], g->map->grid[j - 2], \
		ft_strlen(g->map->grid[j - 2]));
}

static int	ft_check_players(t_game *g)
{
	int		i;
	int		j;
	bool	player;

	i = -1;
	player = false;
	while (++i < g->map->height)
	{
		j = 0;
		while (g->map->grid[i][j])
		{
			if (g->map->grid[i][j] == 'N' || g->map->grid[i][j] == 'S'
				|| g->map->grid[i][j] == 'E' || g->map->grid[i][j] == 'W')
			{
				if (player == true)
					return (ft_putstr_fd("Error\nToo many players\n", 2), 0);
				player = true;
			}
			j++;
		}
	}
	return (1);
}

static void	ft_player_position(t_game *g, int i, int j)
{
	if (g->map->grid[i][j] == 'N')
		g->map->n = true;
	else if (g->map->grid[i][j] == 'S')
		g->map->s = true;
	else if (g->map->grid[i][j] == 'W')
		g->map->w = true;
	else if (g->map->grid[i][j] == 'E')
		g->map->e = true;
}

void	ft_find_player(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	g->p = ft_calloc(sizeof(t_player), 1);
	if (ft_check_players(g) == 0)
		return (ft_clean_all(g, g->cub_file), exit(0));
	while (++i < g->map->height)
	{
		j = -1;
		while (g->map->grid[i][++j])
		{
			if (g->map->grid[i][j] == 'N' || g->map->grid[i][j] == 'S'
				|| g->map->grid[i][j] == 'E' || g->map->grid[i][j] == 'W')
			{
				ft_player_position(g, i, j);
				ft_player_init(g, i, j);
				break ;
			}
		}
	}
}
