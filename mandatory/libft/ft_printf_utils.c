/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:19:18 by thsousa           #+#    #+#             */
/*   Updated: 2022/08/23 13:29:21 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	put_ptr(unsigned long i)
{
	char	*base;
	int		j;

	base = "0123456789abcdef";
	j = 0;
	if (i == 0)
		j += put_char('0');
	else
	{
		if (i >= 16)
		{
			put_ptr(i / 16);
			put_ptr(i % 16);
		}
		else
			put_char(base[i]);
		j += count_hexa(i);
	}
	return (j);
}

int	put_itoa(int i)
{
	char	*str;
	size_t	n_len;

	n_len = ft_count(i);
	str = malloc(n_len + 1 * sizeof (char));
	if (!str)
		return (0);
	str[n_len--] = '\0';
	if (i < 0)
	{
		i *= (-1);
		str[0] = '-';
	}
	if (i == 0)
		str[0] = '0';
	str = ft_numb(str, i, n_len);
	free(str);
	return (put_str(str));
}
