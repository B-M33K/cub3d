/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:04:14 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 09:57:30 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	l;
	unsigned int	nl;

	nl = ft_strlen(needle);
	if (nl == 0)
		return ((char *)haystack);
	if (len == 0)
		return (0);
	l = len - nl + 1;
	while (*haystack && l > 0)
	{
		if (!ft_strncmp(haystack, needle, nl))
			return ((char *)haystack);
		haystack++;
		l--;
	}
	return (0);
}
