/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 04:11:49 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 18:06:05 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_count_line_map(t_game *g)
{
	int	i;
	int	count;

	i = ft_find_map(g);
	count = 0;
	while (g->cub_file->cub_file[i])
	{
		count++;
		i++;
	}
	g->map->height = count;
}

void	ft_check_map_char(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map->grid[i])
	{
		j = 0;
		while (g->map->grid[i][j])
		{
			if (g->map->grid[i][j] != '0' && g->map->grid[i][j] != '1' && \
			g->map->grid[i][j] != 'S' && g->map->grid[i][j] != 'N' && \
			g->map->grid[i][j] != 'W' && g->map->grid[i][j] != 'E' && \
			g->map->grid[i][j] != ' ')
			{
				ft_putstr_fd("Error \n invalid caracter in map\n", 2);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	ft_is_player2(t_game *g, int i, int j)
{
	if (g->map->grid[i][j] == 'N' || g->map->grid[i][j] == 'S'
		|| g->map->grid[i][j] == 'E' || g->map->grid[i][j] == 'W')
		return (1);
	return (0);
}

void	ft_check_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->map->grid[++i])
	{
		j = -1;
		while (g->map->grid[i][++j])
		{
			if (g->map->grid[i][j] == '0')
			{
				if (!((g->map->grid[i][j + 1] == '1' || \
	g->map->grid[i][j + 1] == '0' || ft_is_player2(g, i, j + 1)) && \
	(g->map->grid[i][j - 1] == '1' || g->map->grid[i][j - 1] == '0' || \
	ft_is_player2(g, i, j - 1)) && (g->map->grid[i + 1][j] == '1' || \
	g->map->grid[i + 1][j] == '0' || ft_is_player2(g, i + 1, j)) && \
	(g->map->grid[i - 1][j] == '1' || g->map->grid[i - 1][j] == '0' || \
	ft_is_player2(g, i - 1, j))))
				{
					ft_putstr_fd("Error \n invalid map\n", 2);
					exit(1);
				}
			}
		}
	}
}

void	ft_get_map(t_game *g)
{
	int	i;
	int	j;

	ft_count_line_map(g);
	i = ft_find_map(g);
	j = 0;
	g->map->grid = ft_calloc(g->map->height + 1, sizeof(char *));
	while (g->cub_file->cub_file[i])
	{
		g->map->grid[j] = ft_strdup(g->cub_file->cub_file[i]);
		if (g->map->width < (int) ft_strlen(g->map->grid[j]))
			g->map->width = ft_strlen(g->map->grid[j]);
		i++;
		j++;
	}
	ft_check_map_char(g);
	ft_check_map(g);
	ft_find_player(g);
	ft_copy_map(g);
}
