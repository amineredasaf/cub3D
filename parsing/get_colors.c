/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 10:38:38 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 12:29:40 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_colors(t_data *data)
{
	int	i;

	i = 0;
	while (data->sides.f_txt[i] && data->sides.f_txt[i] != '\n')
		i++;
	if (data->sides.f_txt[i])
		data->sides.f_txt[i] = '\0';
	i = 0;
	while (data->sides.c_txt[i] && data->sides.c_txt[i] != '\n')
		i++;
	if (data->sides.c_txt[i])
		data->sides.c_txt[i] = '\0';
	data->floor.splited = ft_split(data->sides.f_txt, ',');
	data->ceiling.splited = ft_split(data->sides.c_txt, ',');
	free(data->sides.c_txt);
	free(data->sides.f_txt);
}