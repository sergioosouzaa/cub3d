/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:38:05 by thsousa           #+#    #+#             */
/*   Updated: 2022/05/16 14:59:46 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_space(int c)
{
	if (c == '\n' || c == '\t' || c == ' '
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_val(int sig)
{	
	if (sig > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			sig;
	long		val;
	long		temp;

	sig = 1;
	val = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sig = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		temp = val;
		val = (val * 10) + *str++ - 48;
		if (val < temp)
			return (ft_val(sig));
	}
	return (sig * val);
}
