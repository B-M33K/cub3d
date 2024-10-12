/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_numbers_rgb.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:13:48 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 20:46:21 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_skip_zero(char **rgb, int i, int j)
{
	int	k;

	k = 0;
	while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
		j++;
	while (rgb[i][j] == '0')
		j++;
	k = j - 1;
	while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
		j++;
	if (rgb[i][j] == '\0')
		return (k);
	return (j);
}

static int	ft_count_numbers(char **rgb, int i, int count)
{
	int	j;

	if (ft_check_if_only_one_num(rgb) == 0)
		return (ft_clean_all_rgb(rgb, NULL), 0);
	while (rgb[++i])
	{
		j = 0;
		j = ft_skip_zero(rgb, i, j);
		while (rgb[i][j] != '\0')
		{
			if (rgb[i][j] >= '0' && rgb[i][j] <= '9')
			{
				count++;
				break ;
			}
			j++;
		}
	}
	if (count != 3)
	{
		ft_putstr_fd("Error\nThere must be 3 numbers in RGB\n", 2);
		ft_clean_all_rgb(rgb, NULL);
		return (0);
	}
	return (1);
}

static int	ft_not_allowed_in_rgb(int i, int j, char **rgb)
{
	if ((rgb[i][j] > 32 && rgb[i][j] < 48)
		|| (rgb[i][j] > 57 && rgb[i][j] < 127))
		return (1);
	return (0);
}

static void	ft_only_numbers(char **rgb, t_game *g)
{
	ft_putstr_fd("Error\nOnly numbers are allowed in RGB\n", 2);
	ft_clean_all_rgb_(rgb, NULL, g);
}

void	ft_check_numbers_rgb(char **rgb, t_game *g)
{
	int	i;
	int	j;

	i = 0;
	if (ft_count_numbers(rgb, -1, 0) == 0)
		return (ft_clean_all(g, g->cub_file), exit(0));
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j] != '\0')
		{
			if (ft_not_allowed_in_rgb(i, j, rgb))
				ft_only_numbers(rgb, g);
			j++;
		}
		i++;
	}
}
