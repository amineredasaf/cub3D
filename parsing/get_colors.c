/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 14:20:27 by yabtaour         ###   ########.fr       */
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
}