/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:37:01 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:48:37 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	find;
	int		i;

	str = (char *) s;
	find = (char) c;
	i = 0;
	while (*str != find)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}
