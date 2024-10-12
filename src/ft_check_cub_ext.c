/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cub_ext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibouaddi <ibouaddi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:50:51 by ibouaddi          #+#    #+#             */
/*   Updated: 2023/12/11 02:05:43 by ibouaddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_check_cub_ext(char *cub_file)
{
	int	i;

	i = 0;
	while (cub_file[i])
		i++;
	if (cub_file[i - 1] == 'b' && cub_file[i - 2] == 'u' \
	&& cub_file[i - 3] == 'c' && cub_file[i - 4] == '.')
		return (0);
	return (ft_putstr_fd("Error\nFile should have .cub extension!\n", 2), 1);
}
