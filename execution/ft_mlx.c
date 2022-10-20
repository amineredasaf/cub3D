/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:24:55 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/19 08:42:49 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color)
{
	// char	*dst;

	// {
	// 	dst = data->mlx_s.buff + (y * data->mlx_s.llength + x * (data->mlx_s.bpp / 8));
	// 	*(unsigned int *)dst = color;
	// }
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{

		int pixel = (y * data->mlx_s.llength) + (x * data->mlx_s.bpp / 8);
		data->mlx_s.buff[pixel + 0] = (color) & 0xFF;
		data->mlx_s.buff[pixel + 1] = (color >> 8) & 0xFF;
		data->mlx_s.buff[pixel + 2] = (color >> 16) & 0xFF;
	}
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	t_mlx	map;

	map = data->mlx_s;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x, y);
}


// void	put_pixel(t_data *data, int color, int alpha)
// {
// 	int	pixel;
// 	int	x;
// 	int	y;

// 	x = data->point.x;
// 	y = data->point.y;
// 	pixel = (y * data->line_length) + (x * data->bits_per_pixel / 8);
// 	if (data->endian == 1 && pixel > 0)
// 	{
// 		data->addr[pixel + 0] = alpha;
// 		data->addr[pixel + 1] = (color >> 16) & 0xFF;
// 		data->addr[pixel + 2] = (color >> 8) & 0xFF;
// 		data->addr[pixel + 3] = (color) & 0xFF;
// 	}
// 	else if (data->endian == 0 && pixel > 0)
// 	{
// 		data->addr[pixel + 0] = (color) & 0xFF;
// 		data->addr[pixel + 1] = (color >> 8) & 0xFF;
// 		data->addr[pixel + 2] = (color >> 16) & 0xFF;
// 		data->addr[pixel + 3] = alpha;
// 	}
// }