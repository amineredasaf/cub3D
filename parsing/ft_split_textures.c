/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:52:01 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/28 22:32:00 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this function creates a 2D table for textures
void	ft_split_textures(t_data *data)
{
	data->textures = malloc(sizeof(char *) * 5);
	if (!data->textures)
	{
		free_allocation(data);
		ft_free_split(data->file_content);
		exit(ft_print_error(E_ALLOCATION_FAILED));
	}
	data->textures[0] = ft_strdup(data->sides.no_txt);
	free(data->sides.no_txt);
	data->sides.no_txt = NULL;
	data->textures[1] = ft_strdup(data->sides.so_txt);
	free(data->sides.so_txt);
	data->sides.so_txt = NULL;
	data->textures[2] = ft_strdup(data->sides.we_txt);
	free(data->sides.we_txt);
	data->sides.we_txt = NULL;
	data->textures[3] = ft_strdup(data->sides.ea_txt);
	free(data->sides.ea_txt);
	data->sides.ea_txt = NULL;
	data->textures[4] = NULL;
}
