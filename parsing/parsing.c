/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:59:35 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/26 20:29:24 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func check for Name And Suffix of the Conf file.
int	ft_check_cub(char *name)
{
	int	i;

	i = 0;
	while (name && name[i])
		i++;
	i = i - 4;
	if (i >= 0)
	{
		if (ft_strcmp(&name[i], ".cub") == 0)
			return (EXIT_SUCCESS);
		ft_print_error(E_SUFFIX);
	}
	else
		ft_print_error(E_FILE_NAME);
	return (EXIT_FAILURE);
}

// this fun open the conf file and return file descriptors
// we open two file descriptors :
// [0] : for counting the number of lines for allocation
// [1] : for reading the content and parse it out.
int	ft_open_map(t_data *data)
{
	data->fd_map[0] = open(data->av[1], O_RDONLY);
	data->fd_map[1] = open(data->av[1], O_RDONLY);
	if (data->fd_map[0] == -1 || data->fd_map[1] == -1)
		return (ft_print_error(E_PERMISSION_DENIED));
	return (EXIT_SUCCESS);
}

// this function store the map content in data->map_s.map
// i delete -1 from substr(*, len -1);
void	ft_get_map(t_data *data)
{
	int		i;
	int		size;
	int		j;
	char	*line;

	size = data->map_s.end_point - data->map_s.start_point;
	i = data->map_s.start_point;
	j = 0;
	data->map_s.map = ft_calloc(size + 1, sizeof(char *));
	while (i < data->map_s.end_point)
	{
		line = data->file_content[i++];
		data->map_s.map[j++] = ft_substr(line, 0, ft_strlen(line));
	}
	data->map_s.map[j] = NULL;
	i = 0;
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

// this func is main func for parsing process.
int	ft_parsing(t_data *data)
{
	if (data->ac != 2)
	{
		ft_print_error(E_ARGC_NB);
		return (EXIT_FAILURE);
	}
	if (ft_check_cub(data->av[1]))
		return (EXIT_FAILURE);
	if (ft_open_map(data))
		return (EXIT_FAILURE);
	ft_read_file(data);
	ft_parse_textures(data);
	ft_split_textures(data);
	ft_parse_map(data);
	ft_get_colors(data);
	ft_get_map(data);
	ft_fill_lines(data, 0, 0);
	ft_free_split(data->file_content);
	return (EXIT_SUCCESS);
}
