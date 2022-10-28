/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:32:42 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 16:37:50 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func read conf file content and allocate space for it
// FD : need to be closed [0]
// data->file_content : need to be freed

int	count_lines(t_data *data)
{
	char	*temp;
	int		i;

	i = 0;
	temp = get_next_line(data->fd_map[0]);
	while (temp)
	{
		free(temp);
		i++;
		temp = get_next_line(data->fd_map[0]);
	}
	close(data->fd_map[0]);
	return (i);
}

void	ft_read_file(t_data *data)
{
	char	*line;
	int		i;

	i = count_lines(data);
	line = NULL;
	data->map_s.end_point = i;
	if (i == 0)
		exit (ft_print_error(E_EMPTY_FILE));
	data->file_content = ft_calloc(i + 1, sizeof(char *));
	if (!data->file_content)
		exit(ft_print_error(E_ALLOCATION_FAILED));
	i = 0;
	line = get_next_line(data->fd_map[1]);
	while (line)
	{
		data->file_content[i++] = ft_substr(line, 0, ft_strlen(line));
		free(line);
		line = get_next_line(data->fd_map[1]);
	}
	close(data->fd_map[1]);
}
