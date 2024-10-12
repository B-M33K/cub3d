/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 02:58:36 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 20:56:34 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_get_texture2(t_game *g, int i, int j)
{
	t_cub_file	*cub;

	cub = g->cub_file;
	if (cub->cub_file[i][j] == 'W' && cub->cub_file[i][j + 1] == 'E'
		&& ft_isspace(cub->cub_file[i][j + 2]))
	{
		while (cub->cub_file[i][j + 2] == ' ' \
		|| cub->cub_file[i][j + 2] == '\t')
			j++;
		g->tex[1][0] = ft_strtrim(ft_strdup(cub->cub_file[i] + j + 2), " \t");
	}
	else if (cub->cub_file[i][j] == 'E' && cub->cub_file[i][j + 1] == 'A'
		&& ft_isspace(cub->cub_file[i][j + 2]))
	{
		while (cub->cub_file[i][j + 2] == ' ' \
		|| cub->cub_file[i][j + 2] == '\t')
			j++;
		g->tex[1][1] = ft_strtrim(ft_strdup(cub->cub_file[i] + j + 2), " \t");
	}
}

void	ft_get_texture(t_game *g, int i, int j)
{
	t_cub_file	*cub;

	cub = g->cub_file;
	if (cub->cub_file[i][j] == 'N' && cub->cub_file[i][j + 1] == 'O'
		&& ft_isspace(cub->cub_file[i][j + 2]))
	{
		while (cub->cub_file[i][j + 2] == ' ' \
		|| cub->cub_file[i][j + 2] == '\t')
			j++;
		g->tex[0][0] = ft_strtrim(ft_strdup(cub->cub_file[i] + j + 2), " \t");
	}
	else if (cub->cub_file[i][j] == 'S' && cub->cub_file[i][j + 1] == 'O'
		&& ft_isspace(cub->cub_file[i][j + 2]))
	{
		while (cub->cub_file[i][j + 2] == ' ' \
		|| cub->cub_file[i][j + 2] == '\t')
			j++;
		g->tex[0][1] = ft_strtrim(ft_strdup(cub->cub_file[i] + j + 2), " \t");
	}
	ft_get_texture2(g, i, j);
}

void	print_textures_err(t_game *g)
{
	ft_putstr_fd("wrong texture path\n", 2);
	ft_clean_all(g, g->cub_file);
	exit(1);
}

void	ft_parse_and_get_textures(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->cub_file->cub_file[++i])
	{
		j = 0;
		while (g->cub_file->cub_file[i][j])
		{
			while (g->cub_file->cub_file[i][j] == ' ' \
			|| g->cub_file->cub_file[i][j] == '\t')
				j++;
			ft_get_texture(g, i, j);
			if (g->cub_file->cub_file[i][j])
				j++;
		}
	}
	if (access (g->tex[0][0], F_OK) == -1)
		print_textures_err(g);
	else if (access(g->tex[0][1], F_OK) == -1)
		print_textures_err(g);
	else if (access (g->tex[1][0], F_OK))
		print_textures_err(g);
	else if (access (g->tex[1][1], F_OK) == -1)
		print_textures_err(g);
}
