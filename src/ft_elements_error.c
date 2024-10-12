/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elements_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:18:23 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:16:19 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_elements_error(char c, char c2, char c3, t_game *g)
{
	if (c == 'N' && c2 == '0' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'S' && c2 == '0' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'W' && c2 == 'E' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'E' && c2 == 'A' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'C' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else if (c == 'F' && ft_isspace(c3))
		ft_putstr_fd("Error\nElements can't be set more than once\n", 2);
	else
		ft_putstr_fd("Error\nElements are not well formated\n", 2);
	ft_clean_all(g, g->cub_file);
	exit(0);
}
