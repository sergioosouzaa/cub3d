/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:03:24 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/19 14:25:20 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	char	*str1;
	size_t	i;

	if (!f || !s)
		return (0);
	i = 0;
	str1 = (char *)s;
	len = ft_strlen(s);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (str1[i])
	{
		str[i] = f(i, str1[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
