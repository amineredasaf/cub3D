/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:17:21 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/28 16:17:25 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*line;
	int		len;

	line = malloc(1 + BUFFER_SIZE);
	if (!line)
		return (NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len)
	{
		len = read(fd, line, BUFFER_SIZE);
		if (len == -1)
		{
			free(line);
			return (NULL);
		}
		line[len] = '\0';
		str = ft_strjoin(str, line);
	}
	free(line);
	return (str);
}

char	*ft_get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[0])
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	char	*line;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	len = ft_strlen(&str[i + 1]);
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	j = 0;
	i++;
	while (str[i] != '\0')
		line[j++] = str[i++];
	line[j] = '\0';
	free(str);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*current_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current_line = ft_read(fd, current_line);
	if (!current_line)
		return (NULL);
	line = ft_get_line(current_line);
	current_line = ft_get_rest(current_line);
	return (line);
}
