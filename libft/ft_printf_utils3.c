/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:19:19 by thsousa           #+#    #+#             */
/*   Updated: 2022/08/23 13:14:05 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_hexa(unsigned long i)
{
	int	j;

	j = 0;
	while (i != 0)
	{
		j++;
		i = i / 16;
	}
	return (j);
}

int	put_hexa(unsigned int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i == 0)
		return (put_char('0'));
	if (i >= 16)
	{
		put_hexa(i / 16);
		put_hexa(i % 16);
	}
	else
		put_char(base[i]);
	return (count_hexa(i));
}

int	put_hexa_up(unsigned int i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i == 0)
		return (put_char('0'));
	if (i >= 16)
	{
		put_hexa_up(i / 16);
		put_hexa_up(i % 16);
	}
	else
		put_char(base[i]);
	return (count_hexa(i));
}
