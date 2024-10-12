/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:45:40 by obahi             #+#    #+#             */
/*   Updated: 2023/12/13 17:45:42 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_map_not_well_formated(t_game *g)
{
	ft_putstr_fd("Error\nMap not well formated!\n", 2);
	ft_clean_all(g, g->cub_file);
	exit(0);
}

void	ft_not_closed_and_clean(t_game *g)
{
	ft_putstr_fd("Error\nMap not closed or invalid char in map!\n", 2);
	ft_clean_all(g, g->cub_file);
	exit(0);
}

int	ft_above_3_digits(char **rgb, char **rgb_final, int j, t_game *g)
{
	if (j > 3)
	{
		ft_putstr_fd("Error\nToo many digits for colors\n", 2);
		ft_clean_all_rgb_(rgb, rgb_final, g);
	}
	j++;
	return (j);
}

int	ft_find_map(t_game *g)
{
	int			i;
	int			j;
	t_cub_file	*cub;

	i = ft_count_elements(g, 0) + 1;
	cub = g->cub_file;
	if (cub->cub_file[i] == NULL)
		return (ft_map_not_well_formated(g), 0);
	while (cub->cub_file[i][0] == '\0')
		i++;
	while (cub->cub_file[i])
	{
		j = 0;
		while (cub->cub_file[i][j] == ' ' || cub->cub_file[i][j] == '\t')
		{
			if (!(cub->cub_file[i][j] == ' ' || cub->cub_file[i][j] == '\t' \
			|| cub->cub_file[i][j] == '1' || cub->cub_file[i][j] == '0'))
				return (ft_elements_error('0', '0', '0', g), 0);
			j++;
		}
		if (cub->cub_file[i][j] == '1' || cub->cub_file[i][j] == '0')
			return (i);
		i++;
	}
	return (ft_map_not_well_formated(g), 0);
}
