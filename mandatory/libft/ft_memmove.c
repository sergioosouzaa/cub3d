/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:36:14 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:46:53 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*dest;

	str = (char *) src;
	dest = (char *) dst;
	if (!dst && !src)
		return (0);
	if (str < dest)
	{
		str += len;
		dest += len;
		while (len--)
			*--dest = *--str;
	}
	else
	{
		while (len--)
			*dest++ = *str++;
	}
	return (dst);
}
