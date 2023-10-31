/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 08:08:11 by obahi             #+#    #+#             */
/*   Updated: 2023/08/13 08:20:34 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	len;
	int	i;

	len = ft_strlen(needle);
	if (len == 0)
		return ((char *)haystack);
	i = 0;
	while (*(haystack + i))
	{
		if (!ft_strncmp(haystack + i, needle, len))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
