/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:23:37 by yabtaour          #+#    #+#             */
/*   Updated: 2022/10/24 10:55:32 by rsaf             ###   ########.fr       */
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
	data->file_content = NULL;
	data->map_s.map = 0;
	data->side.img_wid = 0;
	data->side.img_hie = 0;
	data->side.llength = 0;
	data->side.bpp = 0;
	data->side.ein = 0;
	data->key_flags.move_backward = 0;
	data->key_flags.move_forward = 0;
	data->key_flags.move_left = 0;
	data->key_flags.move_right = 0;
	data->key_flags.rotate_left = 0;
	data->key_flags.rotate_right = 0;
	ft_initialize_textures(&data->sides);
}