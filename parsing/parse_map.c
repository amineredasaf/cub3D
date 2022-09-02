/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:31:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/02 14:25:39 by rsaf             ###   ########.fr       */
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
		else if (!ft_isspace(line[y][x]))
			exit (ft_print_error(E_CHARACTERS));
		y++;
	}
	return (EXIT_FAILURE);
}

// this func loop on the map lines and checkes if conditions are valid
// closed variable: TRUE if The Map start with '1', false if Not and error
int	ft_elements_checker(char **line, int broder_flag)
{
	int	x;
	int	len;
	int closed;

	x = 0;
	len = ft_strlen(line[x]);
	closed = FAlSE;
	if (broder_flag == W_FIRST)
	{
		while(line[0][x] && line[0][x] != '\n')
		{
			if (line[0][x] != '1' && !ft_isspace(line[0][x]))
				exit(ft_print_error(E_WALLS));
			else if (ft_isspace(line[0][x]))
				ft_check_vertical(line , 0, x);
			x++;
		}
	}
	if (broder_flag == W_INSIDE)
	{
		while(line[0] && line[0][x] != '\n')
		{
			if (line[0][x] == '1')
				closed = TRUE;
			else if (ft_isspace(line[0][x]) && line[0][x] != '0')
				ft_check_vertical(line, 0, x);
			else if (line[0][x] == '0' && (line[0][x + 1] != '1' && line[0][x + 1] != '0'))
				exit(ft_print_error(E_CHARACTERS));
			else if (line[0][x] == '0' && closed == FAlSE)
				exit(ft_print_error(E_WALLS));
			x++;
		}
	}
	if (broder_flag == W_LAST)
	{
		while(line[0] && line[0][x] != '\0')
		{
			if (line[0][x] == '1')
				closed = TRUE;
			else if (line[0][x] != '1' && line[0][x] != ' ')
				exit(ft_print_error(E_WALLS));
			x++;
		}
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
	while (data->file_content[x])
	{
		if (x == map->start_point)
			ft_elements_checker(&data->file_content[x], W_FIRST);
		else if (data->file_content[x + 1] == NULL)
			ft_elements_checker(&data->file_content[x], W_LAST);
		else if (x != map->start_point)
			ft_elements_checker(&data->file_content[x], W_INSIDE);
		x++;
	}
	return (EXIT_SUCCESS);
}