/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/28 22:26:38 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//this function checks how many commas are there in the color
void	ft_check_comma(t_data *data, char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
	{
		ft_free_split(data->file_content);
		ft_free_split(data->textures);
		free_allocation(data);
		exit (ft_print_error(E_COLOR));
	}
}

//this function cheks how many fields are there in the color
void	ft_check_fields(t_data *data, char **fields)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i != 3)
	{
		if (data->floor.splited)
			ft_free_split(data->floor.splited);
		if (data->ceiling.splited)
			ft_free_split(data->ceiling.splited);
		ft_free_split(data->file_content);
		ft_free_split(data->textures);
		exit (ft_print_error(E_COLOR));
	}
}

// this function converts the colors from char * to int using atoi
void	ft_store_color(t_data *data, int flag)
{
	if (flag == S_F)
	{
		data->floor.r = ft_atoi(data->floor.splited[0]);
		data->floor.g = ft_atoi(data->floor.splited[1]);
		data->floor.b = ft_atoi(data->floor.splited[2]);
		ft_free_split(data->floor.splited);
	}
	else if (flag == S_C)
	{
		data->ceiling.r = ft_atoi(data->ceiling.splited[0]);
		data->ceiling.g = ft_atoi(data->ceiling.splited[1]);
		data->ceiling.b = ft_atoi(data->ceiling.splited[2]);
		ft_free_split(data->ceiling.splited);
	}
}

// this function function checks the range of colors and converts rgb to int
// the formula is (r * 1 << 16) + (g * 1 << 8) + (b * 1 << 0)
void	ft_convert_color(t_data *data, int flag)
{
	if (flag == S_F)
	{
		if (data->floor.b > 255 || data->floor.r > 255 || data->floor.g > 255
			|| data->floor.b < 0 || data->floor.r < 0 || data->floor.g < 0)
			kill_leaks(data, "FT", E_COLOR);
		data->floor.final_color = data->floor.b << 16;
		data->floor.final_color += data->floor.g << 8;
		data->floor.final_color += data->floor.r;
	}
	if (flag == S_C)
	{
		if (data->ceiling.b > 255 || data->ceiling.r > 255
			|| data->ceiling.g > 255
			|| data->ceiling.b < 0 || data->ceiling.r < 0
			|| data->ceiling.g < 0)
			kill_leaks(data, "FT", E_COLOR);
		data->ceiling.final_color = data->ceiling.b << 16;
		data->ceiling.final_color += data->ceiling.g << 8;
		data->ceiling.final_color += data->ceiling.r;
	}
}

// this is the main function for parsing the colors
void	ft_get_colors(t_data *data)
{
	ft_check_comma(data, data->sides.c_txt);
	ft_check_comma(data, data->sides.f_txt);
	data->floor.splited = ft_split(data->sides.f_txt, ',');
	data->ceiling.splited = ft_split(data->sides.c_txt, ',');
	free(data->sides.c_txt);
	free(data->sides.f_txt);
	ft_check_fields(data, data->floor.splited);
	ft_check_fields(data, data->ceiling.splited);
	ft_store_color(data, S_F);
	ft_store_color(data, S_C);
	ft_convert_color(data, S_F);
	ft_convert_color(data, S_C);
}
