/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:34:30 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 07:07:01 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_(char const *s1, char const *s2, char c)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (join)
	{
		i = 0;
		while (*(s1 + i))
		{
			*(join + i) = *(s1 + i);
			i++;
		}
		j = 0;
		while (*(s2 + j))
		{
			*(join + i + j) = *(s2 + j);
			j++;
		}
		*(join + i + j) = c;
		*(join + i + j + 1) = 0;
	}
	return (join);
}
