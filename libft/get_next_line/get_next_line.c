/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thsousa <thsousa@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:25:12 by thsousa           #+#    #+#             */
/*   Updated: 2023/03/14 18:09:07 by thsousa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(char *line)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	str = malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_save(char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = malloc((ft_strlen(line) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

static char	*ft_save_line(int fd, char *line)
{
	char	*str;
	int		size;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (NULL);
	size = 1;
	while (!ft_strchr(line, '\n') && size)
	{
		size = read(fd, str, BUFFER_SIZE);
		if (size == -1)
		{
			free(str);
			return (NULL);
		}
		str[size] = '\0';
		if (!line)
		{
			line = malloc(1 * sizeof(char));
			*line = '\0';
		}
		line = ft_strjoin(line, str);
	}
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_save_line(fd, line);
	if (!line)
		return (NULL);
	str = ft_read(line);
	line = ft_save(line);
	return (str);
}
