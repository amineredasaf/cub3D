/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 14:59:35 by yabtaour          #+#    #+#             */
/*   Updated: 2022/09/02 14:44:44 by rsaf             ###   ########.fr       */
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

// this func read conf file content and allocate space for it
// FD : need to be closed [0]
// data->file_content : need to be freed
void	ft_read_file(t_data *data)
{
	char	*line;
	int		i;
	int		flag;
	
	flag = 0;
	i = 0;
	line = NULL;
	while (get_next_line(data->fd_map[0]))
		i++;
	if (i == 0)
		exit (ft_print_error(E_EMPTY_FILE));
	data->file_content = malloc(sizeof(char *) * (i + 1));
	if (!data->file_content)
		exit(ft_print_error(E_ALLOCATION_FAILED));
	i = 0;
	while ((line = get_next_line(data->fd_map[1])))
	{
		data->file_content[i++] = ft_substr(line, 0, ft_strlen(line));
		flag++;
		free(line);
	}
	if (!flag)
		ft_print_error(E_FILE_FORMAT);
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
	ft_parse_map(data);
	ft_get_colors(data);
	return (EXIT_SUCCESS);
}