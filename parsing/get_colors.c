/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 16:52:21 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//this function checks how many commas are there in the color
void	ft_check_comma(char *line)
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
		exit (ft_print_error("- Colors configuration is not correct"));
}

//this function cheks how many fields are there in the color
void	ft_check_fields(char **fields)
{
	int	i;

	i = 0;
	while (fields[i])
		i++;
	if (i != 3)
		exit (ft_print_error("- Colors configuration is not correct"));
}

void	ft_store_color(t_data *data, int flag)
{
	if (flag == S_F)
	{
		data->floor.r = ft_atoi(data->floor.splited[0]);
		data->floor.g = ft_atoi(data->floor.splited[1]);
		data->floor.b = ft_atoi(data->floor.splited[2]);
	}
	else if (flag == S_C)
	{
		data->ceiling.r = ft_atoi(data->ceiling.splited[0]);
		data->ceiling.g = ft_atoi(data->ceiling.splited[1]);
		data->ceiling.b = ft_atoi(data->ceiling.splited[2]);		
	}
}

void	ft_convert_color(t_data *data, int flag)
{
	if (flag == S_F)
	{
		if (data->floor.b > 255 || data->floor.r > 255 || data->floor.g > 255
			|| data->floor.b < 0 || data->floor.r < 0 || data->floor.g < 0)
			exit (ft_print_error("- Color configuration is no correct."));
		// here I need to call the function that converts the color to int and store it in data->floor.final_color
	}
	if (flag == S_C)
	{
		if (data->ceiling.b > 255 || data->ceiling.r > 255 || data->ceiling.g > 255
			|| data->ceiling.b < 0 || data->ceiling.r < 0 || data->ceiling.g < 0)
			exit (ft_print_error("- Color configuration is no correct."));
		// here I need to call the function that converts the color to int and store it in data->ceiling.final_color
	}
}

void	ft_get_colors(t_data *data)
{
	ft_check_comma(data->sides.c_txt);
	ft_check_comma(data->sides.f_txt);
	data->floor.splited = ft_split(data->sides.f_txt, ',');
	data->ceiling.splited = ft_split(data->sides.c_txt, ',');
	free(data->sides.c_txt);
	free(data->sides.f_txt);
	ft_check_fields(data->floor.splited);
	ft_check_fields(data->ceiling.splited);
	ft_store_color(data, S_F);
	ft_store_color(data, S_C);
	ft_convert_color(data, S_F);
	ft_convert_color(data, S_C);
}