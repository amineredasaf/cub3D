/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:58:03 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/31 13:02:58 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this function checks if the line is before the map or not
int	ft_is_map(char *line)
{
	if (!ft_isspace(line[0]) && line[0] != '1')
		return (FAlSE);
	return (TRUE);
}

// this func compare sides and colors [ NO - SO - WE - EA - F - C]
int	ft_issides(char *line, char a, char b, int flag)
{
	if (flag == SIDE && line && line[0] == a && line[1] == b && ft_isspace(line[2]))
		return (TRUE);
	else if (flag == COLOR && line && line[0] == a && ft_isspace(line[1]))
		return (TRUE);
	return (FAlSE);
}

// we need to add protection here for all textures and colors if empty or new line
int	ft_check_after_id(t_data *data)
{
	if (!data->sides.no_txt || data->sides.no_txt[0] == '\n'
		|| !data->sides.so_txt || data->sides.so_txt[0] == '\n'
		|| !data->sides.ea_txt || data->sides.ea_txt[0] == '\n'
		|| !data->sides.we_txt || data->sides.we_txt[0] == '\n'
		|| !data->sides.f_txt || data->sides.f_txt[0] == '\n'
		|| !data->sides.c_txt || data->sides.c_txt[0] == '\n')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
