/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaf <rsaf@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 20:51:34 by rsaf              #+#    #+#             */
/*   Updated: 2022/10/19 09:45:49 by rsaf             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// this func find which key and move to the right direction
// |	0 : A	|	2 : D	|	1 : S	|	13 : W	|
int	key_detector(int keycode, t_data *data)
{
	(void)data;
	if (keycode == 1)
		move_backward(data);
	if (keycode == 13)
		move_forward(data);
	if (keycode == 123)
		rotate_player(data, LEFT);
	if (keycode == 124)
		rotate_player(data, RIGHT);
	if (keycode == 53)
		exit (EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

// this func waitng for key pressed to call the right action
int	key_pressed(t_data *data)
{
	mlx_hook(data->mlx_s.win_ptr, 2, 1L << 2, key_detector, data);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	data.av = argv;
	data.ac = argc;
	ft_initialize_data(&data);
	if (ft_parsing(&data))
		return (EXIT_FAILURE);
	data.mlx_s.mlx_ptr = mlx_init();
	data.mlx_s.win_ptr = mlx_new_window(data.mlx_s.mlx_ptr, W_X, W_Y, "cube");
	data.mlx_s.img_ptr = mlx_new_image(data.mlx_s.mlx_ptr, W_X, W_Y);
	data.mlx_s.buff = mlx_get_data_addr(data.mlx_s.img_ptr, &data.mlx_s.bpp, &data.mlx_s.llength, &data.mlx_s.ein);
	ft_get_starting_angle(&data);
	ft_execution(&data);
	key_pressed(&data);
	mlx_loop(data.mlx_s.mlx_ptr);
}
