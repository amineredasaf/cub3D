/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:31:53 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/01 13:01:57 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_check_vertical(char **line, int y, int x)
{
	int i;

	i = 0;
	while (line[y])
	{
		if (line[y][x] == '1')
			return (EXIT_SUCCESS);
		else if (!ft_isspace(line[y][x]))
			exit (ft_print_error("BLA BLA"));
		y++;
	}
	return (EXIT_FAILURE);
}

int	ft_elements_checker(char **line, int broder_flag)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(line[x]);
	if (broder_flag == W_FIRST_LAST)
	{
		while(line[0][x] && line[0][x] != '\n')
		{
			// printf("%s", line[0]);
			if (line[0][x] != '1' && !ft_isspace(line[0][x]))
				exit(ft_print_error("Tetsing : map not valid"));
			else if (ft_isspace(line[0][x]))
				ft_check_vertical(line , 0, x);
			x++;
		}
	}
	int closed = FAlSE;
	if (broder_flag == W_INSIDE)
	{
		while(line[0] && line[0][x] != '\n' && line[0][x] != '\0')
		{
			if (line[0][0] != '1' && !ft_isspace(line[0][0]) && !closed)
			{
				printf("[%s]\n", line[0]);
				exit(ft_print_error("Tetsing : map not valid inside"));
			}
			else if (ft_isspace(line[0][x]) && (line[0][x + 1] == ' ' || line[0][x + 1] == '1')
				&& (line[0][x - 1] == ' ' || line[0][x - 1] == '1'))
				ft_check_vertical(line , 0, x);
			else if (line[0][x] == '1')
				closed = TRUE;
			else if (line[0][x] != '\n' && line[0][x] != '0')
			{
				printf("x : %d :: [%c]\n", x, line[0][x]);
				exit(ft_print_error("Not Valid"));
			}
			x++;
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_parse_map(t_data *data)
{
	t_map	*map;
	int	x;

	map = &data->map_s;
	x = map->start_point;
	printf("\n------------ %s -----------\n", __func__);
	printf("start point : [ %d ]\n", map->start_point);
	while (data->file_content[x])
	{
		if (x == map->start_point)
			ft_elements_checker(&data->file_content[x], W_FIRST_LAST);
		else if (x != map->start_point)
			ft_elements_checker(&data->file_content[x], W_INSIDE);
		x++;
	}
	printf("\n------------ end -----------\n");
	return (EXIT_SUCCESS);
}