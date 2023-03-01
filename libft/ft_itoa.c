/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:10:34 by thsousa           #+#    #+#             */
/*   Updated: 2022/06/28 16:19:05 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*numb(char *s, unsigned int n, size_t len)
{
	while (n > 0)
	{
		s[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	d;

	d = count(n);
	str = malloc(d + 1 * sizeof (char));
	if (!str)
		return (NULL);
	str[d--] = '\0';
	if (n < 0)
	{	
		n *= (-1);
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str = numb(str, n, d);
	return (str);
}
