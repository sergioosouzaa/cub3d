/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 18:36:04 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 17:50:45 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	ft_ispace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t')
		|| (str[i] >= 'A' && str[i] <= 'Z'))
	i++;
	return (i);
}

size_t	still_space(char *str)
{
	int	len;

	len = ft_strlen(str);
	while (!ft_isalnum(str[len]))
		len--;
	return (len - ft_ispace(str) + 1);
}

void	free_matriz(char **str)
{
	int	i;

	i = 0;
	while (str[i++])
		free (str[i]);
	str = NULL;
}
