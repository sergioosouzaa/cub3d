/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:36:35 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:49:51 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	unsigned int	dstlen;
	unsigned int	srclen;
	unsigned int	j;
	unsigned int	k;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	j = 0;
	k = dstlen;
	if (destsize > 0 && dstlen + 1 < destsize)
	{
		while (src[j] && dstlen + j < destsize -1)
		{
			dst[k] = src[j];
			k++;
			j++;
		}
	}
	dst[k] = '\0';
	if (destsize > dstlen)
		return (srclen + dstlen);
	return (srclen + destsize);
}
