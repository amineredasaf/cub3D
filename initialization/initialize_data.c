/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:23:37 by yabtaour          #+#    #+#             */
/*   Updated: 2022/09/03 12:28:42 by yabtaour         ###   ########.fr       */
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
	ft_initialize_textures(&data->sides);
}