/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:37:30 by obahi             #+#    #+#             */
/*   Updated: 2023/08/20 08:28:30 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_join(char const *s1, char const *s2, char c)
{
	char	*join;
	char	*tmp;

	tmp = 0;
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (join)
	{
		tmp = join;
		while (*s1)
			*tmp++ = *s1++;
		*tmp++ = c;
		while (*s2)
			*tmp++ = *s2++;
		*tmp = '\0';
	}
	return (join);
}
