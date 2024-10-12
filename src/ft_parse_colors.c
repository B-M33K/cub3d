/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 04:59:36 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/13 16:59:36 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_get_rgb_final(char **rgb_final, char **rgb, int i, bool number)
{
	int		j;
	int		k;

	while (rgb[i])
	{
		j = 0;
		k = 0;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		while (rgb[i][j] == '0' && rgb[i][j + 1] == '0')
			j++;
		while (rgb[i][j] >= '0' && rgb[i][j] <= '9')
		{
			number = true;
			rgb_final[i][k] = rgb[i][j];
			j++;
			k++;
		}
		i++;
	}
	if (number == false)
		exit(0);
}

static char	**ft_get_rgb(int j, int l, char **rgb, t_game *g)
{
	char	**rgb_final;
	int		i;

	i = -1;
	ft_check_numbers_rgb(rgb, g);
	rgb_final = ft_calloc(4, sizeof(char *));
	while (rgb[++i])
	{
		l = 0;
		j = 1;
		while (rgb[i][l] == ' ' || rgb[i][l] == '\t')
			l++;
		while (rgb[i][l] == '0')
			l++;
		while (rgb[i][l] >= '0' && rgb[i][l] <= '9')
		{
			j = ft_above_3_digits(rgb, rgb_final, j, g);
			l++;
		}
		rgb_final[i] = ft_calloc(j + 1, sizeof(char));
	}
	rgb_final[i] = 0;
	ft_get_rgb_final(rgb_final, rgb, 0, false);
	return (rgb_final);
}

static void	ft_parse_c_f(int i, t_game *g, int flag)
{
	char	*nbr;
	char	**rgb;
	char	**rgb_final;

	nbr = ft_strdup(g->cub_file->cub_file[i] + 1);
	rgb = ft_split(nbr, ',');
	if (nbr)
		free(nbr);
	rgb_final = ft_get_rgb(0, 0, rgb, g);
	if (ft_assign_rgb_c_f(g, rgb, flag) == 0)
	{
		ft_putstr_fd("Error\nColors need to be set between 0 and 255\n", 2);
		ft_clean_all_rgb_(rgb, rgb_final, g);
	}
	ft_clean_all_rgb(rgb, rgb_final);
}

static void	ft_check_and_parse(int i, int j, t_game *g)
{
	int	k;
	int	count;

	k = j;
	count = 0;
	k++;
	while (g->cub_file->cub_file[i][k] == ' ' \
	|| g->cub_file->cub_file[i][k] == '\t')
		k++;
	if (g->cub_file->cub_file[i][k] < '0' && g->cub_file->cub_file[i][k] > '9')
		ft_elements_error('0', '0', '0', g);
	while (g->cub_file->cub_file[i][k])
	{
		if (g->cub_file->cub_file[i][k] == ',')
			count++;
		k++;
	}
	if (count != 2)
		ft_elements_error('0', '0', '0', g);
	if (g->cub_file->cub_file[i][j] == 'C')
		ft_parse_c_f(i, g, 1);
	if (g->cub_file->cub_file[i][j] == 'F')
		ft_parse_c_f(i, g, 2);
}

void	ft_parse_colors(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (g->cub_file->cub_file[++i])
	{
		j = -1;
		while (g->cub_file->cub_file[i][++j])
		{
			if (g->cub_file->cub_file[i][j] == 'C' && \
			ft_isspace(g->cub_file->cub_file[i][j + 1]))
				ft_check_and_parse(i, j, g);
			if (g->cub_file->cub_file[i][j] == 'F' && \
			ft_isspace(g->cub_file->cub_file[i][j + 1]))
				ft_check_and_parse(i, j, g);
		}
	}
}
