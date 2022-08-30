/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:23:37 by yabtaour          #+#    #+#             */
/*   Updated: 2022/08/30 09:33:54 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_initialize_textures(t_textures *sides)
{
	sides->n_ea = 0;
	sides->n_so = 0;
	sides->n_we = 0;
	sides->n_no = 0;
	sides->no_txt = NULL;
	sides->so_txt = NULL;
	sides->we_txt = NULL;
	sides->ea_txt = NULL;
}

void	ft_initialize_data(t_data *data)
{
	data->file_content = NULL;
	ft_initialize_textures(&data->sides);
}