/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:35:35 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:43:44 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	const char		*str;
	char			*dest;

	str = (const char *)src;
	dest = (char *)dst;
	i = 0;
	if (!src && !dst)
		return (0);
	while (n > 0)
	{
		dest[i] = str[i];
		i++;
		n--;
	}
	return (dest);
}
