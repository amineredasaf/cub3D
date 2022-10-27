/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:02:58 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/27 16:19:35 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
		return (TRUE);
	return (FALSE);
}

void	ft_parse_player(t_data *data)
{
	int	y;
	int	x;

	y = data->map_s.start_point;
	x = 0;
	while (data->file_content[y])
	{
		x = 0;
		while (data->file_content[y][x])
		{
			if (is_player(data->file_content[y][x]) == TRUE)
				data->sides.n_p++;
			x++;
		}
		y++;
	}
	if (data->sides.n_p != 1)
	{
		ft_free_split(data->file_content);
		ft_free_split(data->textures);
		exit(ft_print_error(E_CHARACTERS));
	}
}
