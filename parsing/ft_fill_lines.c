/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:15:41 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 18:15:06 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_line_size(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] != '\0')
		i++;
	return (i);
}

int	ft_longest_line(char **map)
{
	int	value;
	int	i;

	i = 0;
	value = 0;
	while (map && map[i])
	{
		if (ft_map_line_size(map[i]) > value)
			value = ft_map_line_size(map[i]);
		i++;
	}
	return (value);
}

void	insert_new_line(t_data *data, char *temp, int j)
{
	if (data->map_s.map[j])
		free(data->map_s.map[j]);
	data->map_s.map[j] = ft_strdup(temp);
	free(temp);
}

void	ft_fill_lines(t_data *data, int i, int j)
{
	int		size;
	char	*temp;

	size = ft_longest_line(data->map_s.map);
	while (data->map_s.map && data->map_s.map[j])
	{
		temp = NULL;
		i = 0;
		temp = malloc(sizeof(char) * size);
		while (i < size)
		{
			if (ft_isspace(data->map_s.map[j][i])
				|| !ft_isvalid(data->map_s.map[j][i]))
				temp[i] = '1';
			else if (data->map_s.map[j][i] != '\n')
				temp[i] = data->map_s.map[j][i];
			i++;
		}
		temp[i] = '\0';
		insert_new_line(data, temp, j);
		j++;
	}
}
