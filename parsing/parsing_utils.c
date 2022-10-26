/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:58:03 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/26 13:49:31 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this function checks if the line is before the map or not
int	ft_is_map(char *line)
{
	if (!ft_isspace(line[0]) && line[0] != '1')
		return (FALSE);
	return (TRUE);
}

// this func compare sides and colors [ NO - SO - WE - EA - F - C]
int	ft_issides(char *line, char a, char b, int flag)
{
	if (flag == SIDE && line && line[0] == a
		&& line[1] == b && ft_isspace(line[2]))
		return (TRUE);
	else if (flag == COLOR && line && line[0] == a && ft_isspace(line[1]))
		return (TRUE);
	return (FALSE);
}

// we need to add protection here for all textures and colors 
// if empty or new line
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

// this function deletes the new line at the end
char	*ft_delete_new_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i])
		line[i] = '\0';
	return (line);
}

// this function calls the function that deletes the new line at the end 
// of the textures and colors
void	ft_update_txt(t_data *data)
{
	data->sides.c_txt = ft_delete_new_line(data->sides.c_txt);
	data->sides.f_txt = ft_delete_new_line(data->sides.f_txt);
	data->sides.no_txt = ft_delete_new_line(data->sides.no_txt);
	data->sides.so_txt = ft_delete_new_line(data->sides.so_txt);
	data->sides.ea_txt = ft_delete_new_line(data->sides.ea_txt);
	data->sides.we_txt = ft_delete_new_line(data->sides.we_txt);
}
