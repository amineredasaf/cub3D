/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 14:05:37 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	ft_get_colors(t_data *data)
{
	int	i;

	ft_check_comma(data->sides.c_txt);
	ft_check_comma(data->sides.f_txt);
	data->floor.splited = ft_split(data->sides.f_txt, ',');
	data->ceiling.splited = ft_split(data->sides.c_txt, ',');
	free(data->sides.c_txt);
	free(data->sides.f_txt);
	i = 0;
	while (data->floor.splited[i])
		i++;
	if (i != 3)
		exit (ft_print_error("- Colors configuration is not correct"));
	i = 0;
	while (data->ceiling.splited[i])
		i++;
	if (i != 3)
		exit (ft_print_error("- Colors configuration is not correct"));	
}