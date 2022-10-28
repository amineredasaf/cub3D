/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_killer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:16:47 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 22:29:31 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	kill_leaks(t_data *data, char *flag, char *mesg)
{
	int	i;

	i = 0;
	while (flag[i])
	{
		if (flag[i] == 'F')
			ft_free_split(data->file_content);
		if (flag[i] == 'T')
			ft_free_split(data->textures);
		if (flag[i] == 'M')
			ft_free_split(data->map_s.map);
		i++;
	}
	system("leaks cub3d");
	exit(ft_print_error(mesg));
}

void	freeit(t_data *data, char *line)
{
	free_allocation(data);
	if (line)
		free(line);
	kill_leaks(data, "F", E_FILE_FORMAT);
}

void	free_allocation(t_data *data)
{
	if (data->sides.c_txt != NULL)
		free(data->sides.c_txt);
	if (data->sides.f_txt != NULL)
		free(data->sides.f_txt);
	if (data->sides.ea_txt != NULL)
		free(data->sides.ea_txt);
	if (data->sides.no_txt != NULL)
		free(data->sides.no_txt);
	if (data->sides.so_txt != NULL)
		free(data->sides.so_txt);
	if (data->sides.we_txt != NULL)
		free(data->sides.we_txt);
	system("leaks cub3d");
}
