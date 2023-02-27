/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:11:05 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:50:08 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)

{
	unsigned int	i;
	unsigned int	c;

	i = 0;
	c = ft_strlen(src);
	if (dstsize == 0)
	{
		return (c);
	}
	while (src[i] != '\0' && i < dstsize - 1)
	{
		(dest[i] = src[i]);
		i++;
	}
	dest[i] = '\0';
	return (c);
}
