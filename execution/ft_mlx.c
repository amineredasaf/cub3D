/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:24:55 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/19 08:29:04 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// this func insert img to a buffer pixel by pixel to create a img
void	insert_img_buffer(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > 0 && x < W_X && y > 0 && y < W_Y)
	{
		dst = data->mlx_s.buff + (y * data->mlx_s.llength + x * (data->mlx_s.bpp / 8));
		*(unsigned int*)dst = color;
	}
}

// this func put the images on the window;
void	put_on_win(t_data *data, void *ptr, int x, int y)
{
	t_mlx map;

	map = data->mlx_s;
	mlx_put_image_to_window(map.mlx_ptr, map.win_ptr, ptr, x, y);
}