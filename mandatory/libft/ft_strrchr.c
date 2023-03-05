/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:37:12 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:51:35 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	*null;
	char	t;

	i = 0;
	str = (char *)s;
	t = (char )c;
	null = 0;
	if (c == '\0')
		return (&str[i] + ft_strlen(str));
	while (str[i] != '\0')
	{
		if (str[i] == t)
			null = &str[i];
		i++;
	}
	return (null);
}
