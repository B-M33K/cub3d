/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:13:37 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/14 11:01:15 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_assign_elements(char c, char c2, char c3, t_game *g)
{
	if (c == 'N' && c2 == 'O' && ft_isspace(c3)
		&& g->cub_file->north == false)
		g->cub_file->north = true;
	else if (c == 'S' && c2 == 'O' && ft_isspace(c3)
		&& g->cub_file->south == false)
		g->cub_file->south = true;
	else if (c == 'W' && c2 == 'E' && ft_isspace(c3)
		&& g->cub_file->west == false)
		g->cub_file->west = true;
	else if (c == 'E' && c2 == 'A' && ft_isspace(c3)
		&& g->cub_file->east == false)
		g->cub_file->east = true;
	else if (c == 'C' && ft_isspace(c2) && g->cub_file->ceiling == false)
		g->cub_file->ceiling = true;
	else if (c == 'F' && ft_isspace(c2) && g->cub_file->floor == false)
		g->cub_file->floor = true;
	else if ((c == 'N' && c2 == 'O' && g->cub_file->north == true)
		|| (c == 'S' && c2 == 'O' && g->cub_file->south == true)
		|| (c == 'W' && c2 == 'O' && g->cub_file->west == true)
		|| (c == 'E' && c2 == 'O' && g->cub_file->east == true)
		|| (c == 'C' && g->cub_file->ceiling == true)
		|| (c == 'F' && g->cub_file->floor == true))
		ft_elements_error(c, c2, c3, g);
}
