/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabtaour <yabtaour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/09/03 11:53:11 by yabtaour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);

	// void *mlx = mlx_init();
	// void *win = mlx_new_window(mlx, 1000, 1000, "cube");
	// void *img = mlx_new_image(mlx, 20, 20);
	// int bpp;
	// int sizeLine;
	// int en;
	// int *buffer = (int *) mlx_get_data_addr(img, &bpp, &sizeLine, &en);

	// int x = 0;
	// int y = 0;
	
	// while (y < 20) {
	// 	while (x < 20) {
	// 		buffer[x + (y * (sizeLine / 4))] = 0x00FF0000;
	// 		++x;
	// 	}
	// 	++y;
	// 	x = 0;
	// }
	// // x, y = buffer[x + y * sizeLine];
	// mlx_put_image_to_window(mlx, win, img, 1000/2 - (20/2), 0);
	// mlx_loop(mlx);
}