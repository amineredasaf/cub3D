/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:59:35 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/28 17:47:18 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	ft_check_cub(char *name)
{
	int	i;

	i = 0;
	while (name[i])
		i++;
	i--;
	if (name[i] == 'b' && name[i - 1] == 'u'
		&& name[i - 2] == 'c' && name[i - 3] == '.')
		return (0);
	printf("Error\nInvalid name of map ");
	return (1);
}

int	ft_open_map(t_data *data)
{
	data->fd_map = open(data->av[1], O_RDONLY);
	if (data->fd_map == -1)
		return (1);
	return (0);
}

void	ft_read_file(t_data *data)
{
	char	*line;
	data->file = malloc(sizeof(char *) * 100);
	int		i;

	i = 0;
	line = NULL;
	while ((line = get_next_line(data->fd_map)))
	{
		data->file[i] = ft_substr(line, 0, ft_strlen(line));
		i++;
		free(line);
	}
}

int	ft_parsing(t_data *data)
{
	if (data->ac != 2)
	{
		printf("Error\nInvalid number of arguments !!\n");
		return (1);
	}
	if (ft_check_cub(data->av[1]))
		return (1);
	if (ft_open_map(data))
		return (1);
	ft_read_file(data);
	return (0);
}