/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:24:55 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/26 00:29:58 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color)
{
	int	pixel;

	pixel = 0;
	if (x >= 0 && x <= W_X && y >= 0 && y <= W_Y)
	{
		pixel = (y * data->mlx_s.mllength) + (x * data->mlx_s.mbpp / 8);
		data->mlx_s.mbuff[pixel + 0] = (color) & 0xFF;
		data->mlx_s.mbuff[pixel + 1] = (color >> 8) & 0xFF;
		data->mlx_s.mbuff[pixel + 2] = (color >> 16) & 0xFF;
	}
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	t_mlx	map;

	map = data->mlx_s;
	if (x >= 0 && x <= W_X && y >= 0 && y <= W_Y)
		mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x, y);
}

void	prepare_textures(t_data *data)
{
	int		idx;
	t_ptrs	*side;
	t_mlx	*mlx_s;

	idx = 0;
	side = data->side;
	mlx_s = &data->mlx_s;
	mlx_s->frame_ptr = mlx_new_image(mlx_s->mlx_ptr, W_X, W_Y);
	mlx_s->mbuff = mlx_get_data_addr(mlx_s->frame_ptr, &mlx_s->mbpp, \
	&mlx_s->mllength, &mlx_s->mein);
	while (idx <= 3)
	{
		side[idx].img_ptr = mlx_xpm_file_to_image(data->mlx_s.mlx_ptr, \
		data->textures[idx], &side[idx].img_wid, &side[idx].img_hie);
		if (!side[idx].img_ptr)
		{
			ft_free_split(data->textures);
			ft_free_split(data->map_s.map);			
			exit(ft_print_error(E_WALLS));
		}
		side[idx].img_buff = mlx_get_data_addr(side[idx].img_ptr, \
		&side[idx].bpp, \
		&side[idx].llength, &side[idx].ein);
		idx++;
	}
}
