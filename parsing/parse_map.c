/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:31:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/03 12:33:36 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func check looks for the closest '1' after any ' ' [space] detected
int	ft_check_vertical(char **line, int y, int x)
{
	int i;

	i = 0;
	while (line[y])
	{
		if (line[y][x] == '1')
			return (EXIT_SUCCESS);
		else if (!ft_isspace(line[y][x]) && line[y][x] != '\n' && line[y][x] != '\0')
			exit (ft_print_error(E_CHARACTERS));
		y++;
	}
	return (EXIT_FAILURE);
}

// this func parse the first line conditions
int	first_line_verification(char **line)
{
	int	x;

	x = 0;
	while(line[0][x] && line[0][x] != '\n')
	{
		if (line[0][x] != '1' && !ft_isspace(line[0][x]))
			exit(ft_print_error("E_WALLS"));
		else if (ft_isspace(line[0][x]))
			ft_check_vertical(line , 0, x);
		x++;
	}
	return (EXIT_SUCCESS);
}

// this func parse the lines conditions inside the map
int	inside_line_verification(char **line, t_data *data)
{
	int	x;
	// int	len;
	// int closed;

	x = 0;
	while(line[1] && line[1][x] != '\n')
	{
		if (line[1][x] == '1')
			data->map_s.closed = TRUE;
		else if (ft_isspace(line[1][x]) && line[1][x] != '0')
			ft_check_vertical(line, 1, x);
		else if (ft_isvalid(line[1][x]) && ((line[1][x + 1] != '1'
				&& !ft_isvalid(line[1][x + 1]))
				|| (line[2][x] != '1' && !ft_isvalid(line[2][x]))
				|| (line[0][x] != '1' && !ft_isvalid(line[0][x]))))
			exit(ft_print_error(E_CHARACTERS));
		else if (ft_isvalid(line[1][x]) && data->map_s.closed == FAlSE)
			exit(ft_print_error("E_WALLS"));
		x++;
	}
	return (EXIT_SUCCESS);
}

// this func parse the last line conditions
int	last_line_verification(char **line, t_data *data)
{
	int	x;
	// int closed;

	x = 0;
	while(line[0] && line[0][x] != '\0')
	{
		if (line[0][x] == '1')
			data->map_s.closed = TRUE;
		else if (line[0][x] != '1' && line[0][x] != ' ' && line[0][x] != '\n')
			exit(ft_print_error(E_WALLS));
		x++;
	}
	return (EXIT_SUCCESS);
}

// this func loop on the map and parse it
// start_point is the start of the map the value is from texture parsing
int	ft_parse_map(t_data *data)
{
	t_map	*map;
	int	x;

	map = &data->map_s;
	x = map->start_point;
	data->map_s.closed = FAlSE;
	while (data->file_content[x])
	{
		if (data->file_content[x][0] == '\n')
			exit(ft_print_error(E_WALLS));
		if (x == map->start_point)
			first_line_verification(&data->file_content[x]);
		else if (data->file_content[x + 1] == NULL)
			last_line_verification(&data->file_content[x], data);
		else if (x != map->start_point)
			inside_line_verification(&data->file_content[x - 1], data);
		x++;
	}
	data->map_s.map_size = data->map_s.end_point - data->map_s.start_point;
	return (EXIT_SUCCESS);
}