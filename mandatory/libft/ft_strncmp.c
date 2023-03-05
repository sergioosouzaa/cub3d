/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:37:24 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/24 09:50:53 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	*str1;

	str = (unsigned char *) s1;
	str1 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && str1[i] == str[i])
	{
		if (str[i] == '\0' || str1[i] == '\0')
			return (0);
		i++;
	}
	return (str[i] - str1[i]);
}
