/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:24:18 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 00:28:13 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

float	ft_line_len(t_data *data, float y)
{
	int	x;
	int	y1;

	x = 0;
	y1 = (int) y;
	if (y >= 0)
	{
		while (data->map_s.map[y1] && \
		data->map_s.map[y1][x] != '\0' && data->map_s.map[y1][x] != '\n')
			x++;
	}
	return (x);
}

int	ft_count_lines(t_data *data)
{
	int	i;

	i = 0;
	while (data->map_s.map[i])
		i++;
	return (i);
}

int	is_wall(t_data *data, int x, int y)
{
	if (data->map_s.map[y][x] != '1')
		return (0);
	else
		return (1);
}

int	color_convert(t_data *data, char *buff, int lenght)
{
	int	pixel;
	int	color;

	color = 0;
	pixel = (data->exe.offset_y * lenght)
		+ (data->exe.offset_x * data->side[0].bpp / 8);
	if (pixel > 0)
	{
		color = buff[pixel + 0];
		color += buff[pixel + 1] << 8;
		color += buff[pixel + 2] << 16;
	}
	return (color);
}
