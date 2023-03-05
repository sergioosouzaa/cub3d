/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:37:55 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:51:12 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char	*str, const char	*needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*str1;
	char			*str2;

	i = 0;
	str2 = (char *) needle;
	str1 = (char *) str;
	if (needle[i] == '\0')
		return (&str1[i]);
	while (str1[i] != '\0' && n > i)
	{
		j = 0;
		if (str1[i] == needle[j])
		{
			while (str1[i + j] == needle[j] && n > i + j)
			{
				j++;
				if (needle[j] == '\0')
					return (&str1[i]);
			}
		}
		i++;
	}	
	return (0);
}
