/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:53:44 by thsousa           #+#    #+#             */
/*   Updated: 2022/07/28 13:52:18 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;

	if (s1 && set)
	{
		if (*s1 && ft_strchr(set, *s1))
			s1++;
		len = ft_strlen(s1) - 1;
		if (len && ft_strchr(set, s1[len]))
			len--;
		result = ft_substr(s1, 0, len + 1);
		return (result);
	}
	return (NULL);
}
