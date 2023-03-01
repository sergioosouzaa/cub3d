/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasilva <rasilva@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:51:43 by rasilva           #+#    #+#             */
/*   Updated: 2022/05/16 09:11:19 by rasilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_word(char const *s, char c);
static int	countsize_word(char const *s, char c, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		size_word;
	int		count;
	char	**vector;

	i = 0;
	j = 0;
	count = count_word(s, c);
	vector = (char **)malloc((count + 1) * sizeof(char *));
	if (!(vector))
		return ((void *)0);
	while (j < count)
	{
		while (s[i] == c)
			i++;
		size_word = countsize_word(s, c, i);
		vector[j] = ft_substr(s, i, size_word);
		if (!(vector[j]))
			return ((void *)0);
		j++;
		i += size_word;
	}
	vector[j] = 0;
	return (vector);
}

static int	countsize_word(char const *s, char c, int i)
{
	int	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == c))
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}
