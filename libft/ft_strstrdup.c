/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 22:41:38 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 09:58:14 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strstrdup(char **str)
{
	char	**dup;
	int		str_len;
	int		i;

	if (!str)
		return (0);
	str_len = 0;
	i = 0;
	str_len = ft_strstrlen(str);
	dup = malloc((str_len + 1) * sizeof(char *));
	if (!dup)
		return (0);
	while (*(str + i))
	{
		*(dup + i) = ft_strdup(*(str + i));
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}
