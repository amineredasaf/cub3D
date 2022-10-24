/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:23:37 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/24 11:17:49 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_initialize_textures(t_textures *sides)
{
	sides->f_found = 0;
	sides->n_ea = 0;
	sides->n_so = 0;
	sides->n_we = 0;
	sides->n_no = 0;
	sides->n_c = 0;
	sides->n_f = 0;
	sides->no_txt = NULL;
	sides->so_txt = NULL;
	sides->we_txt = NULL;
	sides->ea_txt = NULL;
	sides->f_txt = NULL;
	sides->c_txt = NULL;
}

void	ft_initialize_data(t_data *data)
{
	int sides;

	sides = 3;
	data->file_content = NULL;
	data->map_s.map = 0;
	
	while (sides >= 0)
	{
		data->side[sides].img_wid = 0;
		data->side[sides].img_hie = 0;
		data->side[sides].llength = 0;
		data->side[sides].bpp = 0;
		data->side[sides].ein = 0;
		data->side[sides].img_buff = NULL;
		sides--;
	}
	data->key_flags.move_backward = 0;
	data->key_flags.move_forward = 0;
	data->key_flags.move_left = 0;
	data->key_flags.move_right = 0;
	data->key_flags.rotate_left = 0;
	data->key_flags.rotate_right = 0;
	ft_initialize_textures(&data->sides);
}