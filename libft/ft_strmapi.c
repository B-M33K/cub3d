/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:22:57 by obahi             #+#    #+#             */
/*   Updated: 2023/08/25 09:57:25 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*mapi;

	if (!s)
		return (0);
	len = ft_strlen(s);
	mapi = 0;
	i = 0;
	mapi = malloc(len + 1);
	if (mapi)
	{
		while (i < len)
		{
			*(mapi + i) = f(i, *(char *)(s + i));
			i++;
		}
		*(mapi + i) = '\0';
	}
	return (mapi);
}
