/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:34:51 by thsousa           #+#    #+#             */
/*   Updated: 2022/08/23 13:13:55 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_u(unsigned int n)
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

size_t	ft_count(int i)
{
	int	j;

	j = 0;
	if (i <= 0)
		j = 1;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char	*ft_numb(char *str, unsigned int i, size_t n_len)
{
	while (i > 0)
	{
		str[n_len--] = (i % 10) + '0';
		i = i / 10;
	}
	return (str);
}

int	put_utoa(unsigned int i)
{
	char	*str;
	size_t	n_len;

	n_len = ft_count_u(i);
	str = malloc(n_len + 1 * sizeof (char));
	if (!str)
		return (0);
	str[n_len--] = '\0';
	if (i == 0)
		str[0] = '0';
	str = ft_numb(str, i, n_len);
	free(str);
	return (put_str(str));
}
